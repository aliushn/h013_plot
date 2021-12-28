#include "bmachinecontrol.h"

QString BMachineControl::getWMIHWInfo(int type)
{
    /*
     * 注意：qt调用wmi时，对查询语句要求很严格，所以like之类的句子务必精确才能有结果出来
     *
     * 1. 当前原生网卡地址
     *    SELECT MACAddress ...
     *
     * 2. 硬盘序列号
     *    SELECT PNPDeviceID ...
     *
     * 3. 获取主板序列号
     *    SELECT SerialNumber ...
     *
     * 4. 处理器ID
     *    SELECT ProcessorId ...
     *
     * 5. BIOS序列号
     *    SELECT SerialNumber ...
     *
     * 6. 主板型号
     *    SELECT Product ...
     */

    QString hwInfo;
    QStringList sqlCmd;
    sqlCmd.clear();
    sqlCmd << "SELECT MACAddress FROM Win32_NetworkAdapter WHERE (MACAddress IS NOT NULL) AND (NOT (PNPDeviceID LIKE 'ROOT%'))";
    sqlCmd << "SELECT PNPDeviceID FROM Win32_DiskDrive WHERE( PNPDeviceID IS NOT NULL) AND (MediaType LIKE 'Fixed%')";
    sqlCmd << "SELECT SerialNumber FROM Win32_BaseBoard WHERE (SerialNumber IS NOT NULL)";
    sqlCmd << "SELECT ProcessorId FROM Win32_Processor WHERE (ProcessorId IS NOT NULL)";
    sqlCmd << "SELECT SerialNumber FROM Win32_BIOS WHERE (SerialNumber IS NOT NULL)";
    sqlCmd << "SELECT Product FROM Win32_BaseBoard WHERE (Product IS NOT NULL)";

    QStringList columnName;
    columnName.clear();
    columnName << "MACAddress";
    columnName << "PNPDeviceID";
    columnName << "SerialNumber";
    columnName << "ProcessorId";
    columnName << "SerialNumber";
    columnName << "Product";

    QAxObject *objIWbemLocator = new QAxObject("WbemScripting.SWbemLocator");
    QAxObject *objWMIService = objIWbemLocator->querySubObject("ConnectServer(QString&,QString&)",QString("."), QString("root\\cimv2"));
    QString query;
    if ( type < sqlCmd.size() ) {
        query = sqlCmd.at(type);
    }

    QAxObject *objInterList = objWMIService->querySubObject("ExecQuery(QString&))", query);
    QAxObject *enum1 = objInterList->querySubObject("_NewEnum");

    IEnumVARIANT *enumInterface = 0;
    enum1->queryInterface(IID_IEnumVARIANT, (void**)&enumInterface);
    enumInterface->Reset();

    for ( int i = 0; i < objInterList->dynamicCall("Count").toInt(); ++i )
    {
        VARIANT *theItem = (VARIANT*)malloc(sizeof(VARIANT));
        if ( enumInterface->Next(1, theItem, NULL) != S_FALSE )
        {
            QAxObject *item = new QAxObject((IUnknown *)theItem->punkVal);
            if (item) {
                if ( type<columnName.size() ) {
                    QByteArray datagram(columnName.at(type).toLatin1());
                    const char* tempConstChar = datagram.data();
                    hwInfo=item->dynamicCall(tempConstChar).toString();
                }
            }
        }
    }

    return hwInfo;
}

QString BMachineControl::getKey(QString machineinfo, QString ddMMyyyy, int months)
{
    QString originalStr120;
    if ( machineinfo.isEmpty() ) {
        originalStr120 = QString("machineinfo") + ddMMyyyy + QString::number(months);
    } else {
        originalStr120 = machineinfo + ddMMyyyy + QString::number(months);
    }
    QCryptographicHash sha1(QCryptographicHash::Sha1);

    QByteArray datagram(originalStr120.toLatin1());

    for ( int i = 0; i != datagram.size(); ++i )
    {
        datagram[i] = datagram[i] ^ 'q' ^ 'y';
    }

    const char* tempConstChar = datagram.data();
    sha1.addData(tempConstChar);

    QString activeCode = sha1.result().toHex();

    return activeCode;
}

