#include "mainwindow.h"
#include "usbhidhjw.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTimer>
#include "qdebug.h"
#include <QMessageBox>
#include <QSerialPort>

#include "waterprogressbar.h"

/**********************************
 *
 * *********************************/



bool MainWindow::CreateAnimation(QObject *)
{
    QParallelAnimationGroup *animationGrop=new QParallelAnimationGroup;

    QPropertyAnimation *shakeAnimation =new  QPropertyAnimation(this,"pos");
    shakeAnimation->setStartValue(QPoint(500,200));
    shakeAnimation->setEndValue(QPoint(600,200));
    shakeAnimation->setKeyValueAt(0.1,QPoint(490,200));
    shakeAnimation->setKeyValueAt(0.2,QPoint(510,210));
    shakeAnimation->setKeyValueAt(0.5,QPoint(490,200));
    shakeAnimation->setKeyValueAt(0.8,QPoint(495,203));
    shakeAnimation->setDuration(1500);

    QSequentialAnimationGroup *sepAnimation=new QSequentialAnimationGroup;
    //sepAnimation->addAnimation();

    QPropertyAnimation *pAnimation=new QPropertyAnimation(this,"sasas");
    pAnimation->setTargetObject(this);
    pAnimation->setPropertyName("s");
    pAnimation->setDuration(1000);
    pAnimation->setKeyValueAt(0,255);
    pAnimation->setKeyValueAt(0.5,100);
    pAnimation->setKeyValueAt(1,255);
    pAnimation->setLoopCount(-1);
    pAnimation->setStartValue(QPoint(500,200));
    pAnimation->setEndValue(QPoint(600,200));
    pAnimation->setEasingCurve(QEasingCurve::OutCirc);
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    return false;
}

bool MainWindow::CreateSerialPro(void)
{
    portThread=new QThread();
    SerialObject=new jwSerialPro();
    qDebug()<<"CreateSerialPro";

    SerialObject->moveToThread(portThread);
    connect(SerialObject,SIGNAL(signal_message(QString)),this,SLOT(slot_message(QString)));
    connect(SerialObject,SIGNAL(signal_deleteportobject()),portThread,SLOT(quit()));
    connect(SerialObject,SIGNAL(signal_deleteportobject()),portThread,SLOT(deleLater()));
    connect(portThread,&QThread::finished,portThread,&QObject::deleteLater);
    connect(portThread,SIGNAL(finished()),SerialObject,SLOT(deleteLater));
    connect(portThread,SIGNAL(started()),SerialObject,SLOT(slot_process()));
    connect(SerialObject,&jwSerialPro::signal_byteRead,this,&MainWindow::slot_readByteshjw);
    connect(this,SIGNAL(signal_writeDataRequest(QByteArray)),SerialObject,SLOT(slot_writeBytes(QByteArray)));
    connect(this,SIGNAL(signal_serialportopen(QString,qint32)),SerialObject,SLOT(open(QString,qint32)));
    connect(this,SIGNAL(signal_serialportclose()),SerialObject,SLOT(close()));
    portThread->start();
    return false;
}



#define  PRINTF_STRINg  "diff_data:	"
#define  STR_SIZE_PARSE  (int)7
void MainWindow::slot_readByteshjw(QByteArray data)
{
    QStringList data_list;
	QString info;
    QDateTime dateTime(QDateTime::currentDateTime());
    QString timeStr = "[" + dateTime.toString(" HH:mm:ss.zzz") + "] ";
    QString tmpStr;
    bool ok;
    int power=0;
    //显示
    static QTime time(QTime::currentTime());
    double key = time.elapsed()/500.0;
    if(data.size()<30) return;
     #define  PRINTF_STRINg  "diff_data:	"
    // TODO
    // 似乎直接用QByteArray无法直接取真正的值
    // 这里先转为数组，再判断，需要优化
    uint8_t *pdata = (uint8_t*)info.data();
    uint8_t buf[255] = {0};
    // 根据值判断做逻辑处理，可做成函数
    ui->serial_plot->xAxis->setRange(key, 8, Qt::AlignRight);
    if(data.contains("jw-----------> X_Angle:")){

        QRegExp rx("-?(([1-9]\\d*\\.\\d*)|(0\\.\\d*[1-9]\\d*)|([1-9]\\d*))");
        int p = 0;
        qDebug() << "begin";
        while ((p = rx.indexIn(data, p)) != -1)
        {
            data_list.append(rx.cap(1));
            p += rx.matchedLength(); // 上一个匹配的字符串的长度
        }
        qDebug() << data_list;
        qDebug() << "end";

        if(data_list.count()==3){

            qDebug() << "x angle "<<data_list.at(0);
            qDebug() << "y angle "<<data_list.at(1);
            qDebug() << "z angle "<<data_list.at(2);

            mopengl->setxyz(data_list.at(0).toDouble(&ok),data_list.at(1).toDouble(&ok),data_list.at(2).toDouble(&ok));
            ui->serial_plot->graph(1)->addData(key,double(data_list.at(0).toDouble(&ok)));
            ui->serial_plot->graph(2)->addData(key,double(data_list.at(1).toDouble(&ok)));
            ui->serial_plot->graph(3)->addData(key,double(data_list.at(2).toDouble(&ok)));
        }
        ui->serial_plot->replot();
        data_list.clear();
    }




#if 0
    if(data.size()<100) return;

    if(data.contains("jw:rawdata:"))
    {
        if((data.contains("arith:")&&(data.contains("diff_data:")&&(data.contains("acc_datax:")&&(data.contains("acc_datay:"))))))
        {
            double rawdata=0;
            double arith_rawdata=0;
            double energy_data=0;
            double diff_data=0;
            ////////////////////////////////////////////////////////
            double acc_datax=0;
            double acc_datay=0;


            int rawdata_index=(int)(data.indexOf("rawdata",1)+strlen("rawdata")+1);
            rawdata_index+=(int)STR_SIZE_PARSE;
            if(data.at(rawdata_index+2)==44){
                rawdata=(double)((data.at(rawdata_index+1)-0x30));
            }else if(data.at(rawdata_index+3)==44){
                rawdata=(double)((data.at(rawdata_index+1)-0x30)*10+(data.at(rawdata_index+2)-0x30));
            }else if(data.at(rawdata_index+4)==44){
                rawdata=(double)((data.at(rawdata_index+1)-0x30)*100+(data.at(rawdata_index+2)-0x30)*10+(data.at(rawdata_index+3)-0x30));
            }else if(data.at(rawdata_index+5)==44){
                rawdata=(double)((data.at(rawdata_index+1)-0x30)*1000+(data.at(rawdata_index+2)-0x30)*100+(data.at(rawdata_index+3)-0x30)*10+(data.at(rawdata_index+4)-0x30));
            }
            ////////////////////////////////////////////////////////////////////////////////////////

            int arith_rawdata_index=(int)(data.indexOf("arith",1)+strlen("arith")+1);
            arith_rawdata_index+=(int)STR_SIZE_PARSE;
            if(data.at(arith_rawdata_index+2)==44){
                arith_rawdata=(double)((data.at(arith_rawdata_index+1)-0x30));
            }else if(data.at(arith_rawdata_index+3)==44){
                arith_rawdata=(double)((data.at(arith_rawdata_index+1)-0x30)*10+(data.at(arith_rawdata_index+2)-0x30));
            }else if(data.at(arith_rawdata_index+4)==44){
                arith_rawdata=(double)((data.at(arith_rawdata_index+1)-0x30)*100+(data.at(arith_rawdata_index+2)-0x30)*10+(data.at(arith_rawdata_index+3)-0x30));
            }else if(data.at(arith_rawdata_index+5)==44){
                arith_rawdata=(double)((data.at(arith_rawdata_index+1)-0x30)*1000+(data.at(arith_rawdata_index+2)-0x30)*100+(data.at(arith_rawdata_index+3)-0x30)*10+(data.at(arith_rawdata_index+4)-0x30));
            }
            ////////////////////////////////////////////////////////////////////////////////////////

            int energy_data_index=(int)(data.indexOf("energy_data",1)+strlen("energy_data")+1);
            energy_data_index+=(int)STR_SIZE_PARSE;
            if(data.at(energy_data_index+2)==44){
                energy_data=(double)((data.at(energy_data_index+1)-0x30));
            }else if(data.at(energy_data_index+3)==44){
                energy_data=(double)((data.at(energy_data_index+1)-0x30)*10+(data.at(energy_data_index+2)-0x30));
            }else if(data.at(arith_rawdata_index+4)==44){
                energy_data=(double)((data.at(energy_data_index+1)-0x30)*100+(data.at(energy_data_index+2)-0x30)*10+(data.at(energy_data_index+3)-0x30));
            }else if(data.at(energy_data_index+5)==44){
                energy_data=(double)((data.at(energy_data_index+1)-0x30)*1000+(data.at(energy_data_index+2)-0x30)*100+(data.at(energy_data_index+3)-0x30)*10+(data.at(energy_data_index+4)-0x30));
            }
            ////////////////////////////////////////////////////////////////////////////////////////

            int diff_data_index=(int)(data.indexOf("diff_data",1)+strlen("diff_data")+1);
            diff_data_index+=(int)STR_SIZE_PARSE;
            if(data.at(diff_data_index+2)==44){
                diff_data=(double)((data.at(diff_data_index+1)-0x30));
            }else if(data.at(diff_data_index+3)==44){
                diff_data=(double)((data.at(diff_data_index+1)-0x30)*10+(data.at(diff_data_index+2)-0x30));
            }else if(data.at(diff_data_index+4)==44){
                diff_data=(double)((data.at(diff_data_index+1)-0x30)*100+(data.at(diff_data_index+2)-0x30)*10+(data.at(diff_data_index+3)-0x30));
            }else if(data.at(diff_data_index+5)==44){
                diff_data=(double)((data.at(diff_data_index+1)-0x30)*1000+(data.at(diff_data_index+2)-0x30)*100+(data.at(diff_data_index+3)-0x30)*10+(data.at(diff_data_index+4)-0x30));
            }


            int acc_datax_index=(int)(data.indexOf("acc_datax",1)+strlen("acc_datax")+1);
            acc_datax_index+=(int)STR_SIZE_PARSE;
            if(data.at(acc_datax_index+2)==44){
                acc_datax=(double)((data.at(acc_datax_index+1)-0x30));
            }else if(data.at(acc_datax_index+3)==44){
                acc_datax=(double)((data.at(acc_datax_index+1)-0x30)*10+(data.at(acc_datax_index+2)-0x30));
            }else if(data.at(diff_data_index+4)==44){
                acc_datax=(double)((data.at(acc_datax_index+1)-0x30)*100+(data.at(acc_datax_index+2)-0x30)*10+(data.at(acc_datax_index+3)-0x30));
            }else if(data.at(diff_data_index+5)==44){
                acc_datax=(double)((data.at(acc_datax_index+1)-0x30)*1000+(data.at(acc_datax_index+2)-0x30)*100+(data.at(acc_datax_index+3)-0x30)*10+(data.at(acc_datax_index+4)-0x30));
            }


            int acc_datay_index=(int)(data.indexOf("acc_datay",1)+strlen("acc_datay")+1);
             acc_datay_index+=(int)STR_SIZE_PARSE;
            if(data.at(acc_datay_index+2)==44){
                acc_datay=(double)((data.at(acc_datay_index+1)-0x30));
            }else if(data.at(acc_datay_index+3)==44){
                acc_datay=(double)((data.at(acc_datay_index+1)-0x30)*10+(data.at(acc_datay_index+2)-0x30));
            }else if(data.at(acc_datay_index+4)==44){
                acc_datay=(double)((data.at(acc_datay_index+1)-0x30)*100+(data.at(acc_datay_index+2)-0x30)*10+(data.at(acc_datay_index+3)-0x30));
            }


            int acc_datax_indey=(int)(data.indexOf("acc_datay",1)+strlen("acc_datay")+1);
            acc_datax_indey+=(int)STR_SIZE_PARSE;
            if(data.at(acc_datax_indey+2)==44){
                acc_datax=(double)((data.at(acc_datax_indey+1)-0x30));
            }else if(data.at(acc_datay_index+3)==44){
                acc_datax=(double)((data.at(acc_datax_indey+1)-0x30)*10+(data.at(acc_datax_indey+2)-0x30));
            }else if(data.at(acc_datay_index+4)==44){
                acc_datax=(double)((data.at(acc_datax_indey+1)-0x30)*100+(data.at(acc_datax_indey+2)-0x30)*10+(data.at(acc_datax_indey+3)-0x30));
            }

            //qDebug()<< "rawdata"<<rawdata<<"arith_rawdata"<<arith_rawdata<<"energy_data"<<energy_data<<"diff_data"<<diff_data;
            //ui->serial_plot->graph(0)->addData(key,double(-10)); //取消异常线
            //ui->serial_plot->graph(0)->setVisible(false);
            //display
            ui->serial_plot->graph(1)->addData(key,double(rawdata));
            ui->serial_plot->graph(2)->addData(key,double(arith_rawdata));
            ui->serial_plot->graph(3)->addData(key,double(energy_data));
            ui->serial_plot->graph(4)->addData(key,double(diff_data));
            ui->serial_plot->graph(5)->addData(key,double(acc_datax));
            ui->serial_plot->graph(6)->addData(key,double(acc_datay));

            ui->serial_plot->graph(7)->setVisible(true);
            ui->serial_plot->graph(7)->addData(key,double(ui->dial_9->value()));
            ui->serial_plot->xAxis->setRange(key, 8, Qt::AlignRight);


            //-----------------------------------------------------------------
            if(ui->checkBox_first->checkState()==Qt::CheckState::Unchecked){
               ui->serial_plot->graph(1)->setVisible(false);
            }else{
               ui->serial_plot->graph(1)->setVisible(true);
            }
            if(ui->checkBox_sencond->checkState()==Qt::CheckState::Unchecked){
               ui->serial_plot->graph(2)->setVisible(false);
            }else{
               ui->serial_plot->graph(2)->setVisible(true);
            }
            if(ui->checkBox_third->checkState()==Qt::CheckState::Unchecked){
               ui->serial_plot->graph(3)->setVisible(false);
            }else{
               ui->serial_plot->graph(3)->setVisible(true);
            }

            //-----------------------------------------------------------------
;
        }
    }




    if(data.contains("jw----->presssensor_gather rawdata:"))
    {
        if((data.contains("arith_rawdata:")&&("rawdata:")&&(data.contains("diff_data"))))
        {

            //qDebug()<<"data_size"<<data.size();

            double rawdata=0;
            double arith_rawdata=0;
            double energy_data=0;
            double diff_data=0;

            int rawdata_index=(int)(data.indexOf("rawdata",1)+strlen("rawdata")+1);

            if(data.at(rawdata_index+2)==44){
                rawdata=(data.at(rawdata_index+1)-0x30);
            }else if(data.at(rawdata_index+3)==44){
                rawdata=(data.at(rawdata_index+1)-0x30)*10+(data.at(rawdata_index+2)-0x30);
            }else if(data.at(rawdata_index+4)==44){
                rawdata=(data.at(rawdata_index+1)-0x30)*100+(data.at(rawdata_index+2)-0x30)*10+(data.at(rawdata_index+3)-0x30);
            }
            ////////////////////////////////////////////////////////////////////////////////////////

            int arith_rawdata_index=(int)(data.indexOf("arith_rawdata",1)+strlen("arith_rawdata")+1);
            if(data.at(arith_rawdata_index+2)==44){
                arith_rawdata=(data.at(arith_rawdata_index+1)-0x30);
            }else if(data.at(arith_rawdata_index+3)==44){
                arith_rawdata=(data.at(arith_rawdata_index+1)-0x30)*10+(data.at(arith_rawdata_index+2)-0x30);
            }else if(data.at(arith_rawdata_index+4)==44){
                arith_rawdata=(data.at(arith_rawdata_index+1)-0x30)*100+(data.at(arith_rawdata_index+2)-0x30)*10+(data.at(arith_rawdata_index+3)-0x30);
            }
            ////////////////////////////////////////////////////////////////////////////////////////

            int energy_data_index=(int)(data.indexOf("energy_data",1)+strlen("energy_data")+1);
            if(data.at(energy_data_index+2)==44){
                energy_data=(data.at(energy_data_index+1)-0x30);
            }else if(data.at(energy_data_index+3)==44){
                energy_data=(data.at(energy_data_index+1)-0x30)*10+(data.at(energy_data_index+2)-0x30);
            }else if(data.at(arith_rawdata_index+4)==44){
                energy_data=(data.at(energy_data_index+1)-0x30)*100+(data.at(energy_data_index+2)-0x30)*10+(data.at(energy_data_index+3)-0x30);
            }
            ////////////////////////////////////////////////////////////////////////////////////////
            int diff_data_index=(int)(data.indexOf("diff_data",1)+strlen("diff_data")+1);
            if(data.at(diff_data_index+2)==44){
                diff_data=(data.at(diff_data_index+1)-0x30);
            }else if(data.at(diff_data_index+3)==44){
                diff_data=(data.at(diff_data_index+1)-0x30)*10+(data.at(diff_data_index+2)-0x30);
            }else if(data.at(diff_data_index+4)==44){
                diff_data=(data.at(diff_data_index+1)-0x30)*100+(data.at(diff_data_index+2)-0x30)*10+(data.at(diff_data_index+3)-0x30);
            }
            ui->serial_plot->graph(0)->addData(key,double(rawdata));
            ui->serial_plot->graph(1)->addData(key,double(arith_rawdata));
            ui->serial_plot->graph(2)->addData(key,double(energy_data));
            ui->serial_plot->graph(3)->addData(key,double(diff_data));
            ui->serial_plot->xAxis->setRange(key, 8, Qt::AlignTrailing);
            ui->serial_plot->replot();
        }
    }

#endif

    if(data.contains("LocalsysInfo: wear:1"))
    {
        ui->label_22->setText(tr("主耳未佩戴"));
    }
    if(data.contains("LocalsysInfo: wear:2"))
    {
        ui->label_22->setText(tr("主耳佩戴"));
    }
    if(data.contains("PeersysInfo: wear:1"))
    {
        ui->label_27->setText(tr("副耳未佩戴"));
    }
    if(data.contains("PeersysInfo: wear:2"))
    {
        ui->label_27->setText(tr("副耳佩戴"));
    }
    if(data.contains("jw----->  HAL_PRESSURE_EVENT_DOUBLE_CLICK"))
    {
        ui->label_61->clear();
        ui->label_61->setText(tr("双击"));
    }
    if(data.contains("jw----->  HAL_PRESSURE_EVENT_CLICK"))
    {
        ui->label_61->clear();
        ui->label_61->setText(tr("单击"));
    }
    if(data.contains("jw----->  HAL_PRESSURE_EVENT_THREE_CLICK"))
    {
        ui->label_61->clear();
        ui->label_61->setText(tr("三击"));
    }

    if(data.contains("LocalBatInfo:"))
    {
        if(data.contains("percentage:")){
             //qDebug()<<"1"<<data.at(data.indexOf("percentage:",1));
             //qDebug()<<"2"<<data.at(data.indexOf("percentage:",1)+1);
             //qDebug()<<"3"<<data.at(data.indexOf("percentage:",1)+2);
             //qDebug()<<"pwoer1"<<data.at(data.indexOf("percentage:",1)+strlen("percentage:"));
            // qDebug()<<"pwoer2"<<data.at(data.indexOf("percentage:",1)+strlen("percentage:")+1);
             power=(data.at(data.indexOf("percentage:",1)+strlen("percentage:"))-0x30)*10+(data.at(data.indexOf("percentage:",1)+strlen("percentage:")+1)-0x30);
             //qDebug()<<"batterinfo"<<power;
             //WaterProgressBar *wavebatter=new WaterProgressBar(ui->progressBar_3);

             ui->progressBar_3->setValue(power);
        }
    }
    if(data.contains("PeerBatInfo:")){
        if(data.contains("percentage:")){
             power=(data.at(data.indexOf("percentage:",1)+strlen("percentage:"))-0x30)*10+(data.at(data.indexOf("percentage:",1)+strlen("percentage:")+1)-0x30);
             //qDebug()<<"batterinfo"<<power;
             ui->progressBar_4->setValue(power);
        }

    }
    else
    {
        #if 0
      qDebug()<<"feed------------> %d"<<data.size()<<"数据"<<data.toHex(' ').data();
      for (int i = 0; i < data.size(); i++)
      {
          if(!data.at(i)!=(char)0x20){
               buf[j] = pdata[i];
               j++;
          }
      }
      qDebug()<<"jw data"<<buf[j];
        #endif
    }

    setUpdatesEnabled(false);
    m_rxCnt+=data.size();
    if (m_recvHex == 1){
        info = data.toHex(' ').data();
               qDebug()<<"info"<<info;
    //		 for (int i = 0; i < data.size(); i++)
    //		 {
    //			 tmpStr.sprintf("%02x ", data.at(i));
    //			 qDebug() << data.at(i);
    //			 info.append(tmpStr);
    //		 }
         // ui->textBrowser_3->append(timeStr+QString(info));
    }else{
         info = QString(data);
          ui->textBrowser_3->append(timeStr+QString(data));
    }
    setUpdatesEnabled(true);



    //-----------------------------------------------------------------
    if(ui->checkBox_first->checkState()==Qt::CheckState::Unchecked){
       ui->serial_plot->graph(1)->setVisible(false);
    }else{
       ui->serial_plot->graph(1)->setVisible(true);
    }
    if(ui->checkBox_sencond->checkState()==Qt::CheckState::Unchecked){
       ui->serial_plot->graph(2)->setVisible(false);
    }else{
       ui->serial_plot->graph(2)->setVisible(true);
    }
    if(ui->checkBox_third->checkState()==Qt::CheckState::Unchecked){
       ui->serial_plot->graph(3)->setVisible(false);
    }else{
       ui->serial_plot->graph(3)->setVisible(true);
    }


}

void MainWindow::stringTohexString(QString& str, QString& hexStr)
{
    str=str;
    hexStr=hexStr;
}

int MainWindow::hexStringToString(QString& hexStr, QString& str)
{
    int ret = 0;
    bool ok;
    QByteArray retByte;
    hexStr = hexStr.trimmed();
    hexStr = hexStr.simplified();
    QStringList sl = hexStr.split(" ");

    foreach (QString s, sl)
    {
        if(!s.isEmpty())
        {
            char c = (s.toInt(&ok,16))&0xFF;
            if (ok)
            {
                retByte.append(c);
            }
            else
            {
                ret = -1;
            }
        }
    }

    str = retByte;

    return ret;
}

int MainWindow::hexStringToHexArray(QString& hexStr, QByteArray& arr)
{
    int ret = 0;
    bool ok;
    hexStr = hexStr.trimmed();
    hexStr = hexStr.simplified();
    QStringList sl = hexStr.split(" ");

    foreach (QString s, sl)
    {
        if(!s.isEmpty())
        {
            char c = (s.toInt(&ok,16))&0xFF;
            if (ok)
            {
                arr.append(c);
            }
            else
            {
                ret = -1;
            }
        }
    }

    return ret;
}


int MainWindow::hexArrayToString(QByteArray& hexArr, QString& str)
{
    int ret = 0;
    str = hexArr.toHex(' ').toLower();
    return ret;
}

void MainWindow::CreateSerialportWindow(void)
{
    QStringList list;
    list.clear();
    list  << "9600"<< "115200" << "921600";
    ui->comboBox_2->addItems(list);
    ui->comboBox_2->setCurrentText(tr("115200"));
    //////////////////////////////////////////////////////////////
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        if (-1 == ui->comboBox_7->findText(info.portName()))
            ui->comboBox_7->addItem(info.portName());
    }

#if 0
    mSerialPort.close();
    mSerialPort.setReadBufferSize(1024*100);
    mSerialPort.setSettingsRestoredOnClose(true);

    //连接信号和槽
    QObject::connect(&mSerialPort, &QSerialPort::readyRead, this, &MainWindow::readyRead);
    QObject::connect(this, &MainWindow::sig_deviceChanged, this, &MainWindow::on_deviceChanged);
    // 注册各类设备，可根据要求删减

    // 打开串口

    mSerialPort.setPortName(ui->comboBox_7->currentText());
    mSerialPort.setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);//设置波特率和读写方向
    mSerialPort.setDataBits(QSerialPort::Data8);		//数据位为8位
    mSerialPort.setFlowControl(QSerialPort::NoFlowControl);//无流控制
    mSerialPort.setParity(QSerialPort::NoParity);	//无校验位
    mSerialPort.setStopBits(QSerialPort::OneStop); //一位停止位

#endif


#if 0
    static const GUID GUID_DEVINTERFACE_LIST[] =
    {
    // GUID_DEVINTERFACE_USB_DEVICE
    { 0xA5DCBF10, 0x6530, 0x11D2, { 0x90, 0x1F, 0x00, 0xC0, 0x4F, 0xB9, 0x51, 0xED } },
    // GUID_DEVINTERFACE_DISK
    { 0x53f56307, 0xb6bf, 0x11d0, { 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b } },
    // GUID_DEVINTERFACE_HID,
    { 0x4D1E55B2, 0xF16F, 0x11CF, { 0x88, 0xCB, 0x00, 0x11, 0x11, 0x00, 0x00, 0x30 } },
    // GUID_NDIS_LAN_CLASS
    { 0xad498944, 0x762f, 0x11d0, { 0x8d, 0xcb, 0x00, 0xc0, 0x4f, 0xc3, 0x35, 0x8c } }
    //// GUID_DEVINTERFACE_COMPORT
    //{ 0x86e0d1e0, 0x8089, 0x11d0, { 0x9c, 0xe4, 0x08, 0x00, 0x3e, 0x30, 0x1f, 0x73 } },
    //// GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR
    //{ 0x4D36E978, 0xE325, 0x11CE, { 0xBF, 0xC1, 0x08, 0x00, 0x2B, 0xE1, 0x03, 0x18 } },
    //// GUID_DEVINTERFACE_PARALLEL
    //{ 0x97F76EF0, 0xF883, 0x11D0, { 0xAF, 0x1F, 0x00, 0x00, 0xF8, 0x00, 0x84, 0x5C } },
    //// GUID_DEVINTERFACE_PARCLASS
    //{ 0x811FC6A5, 0xF728, 0x11D0, { 0xA5, 0x37, 0x00, 0x00, 0xF8, 0x75, 0x3E, 0xD1 } }
    };

    //注册插拔事件
    HDEVNOTIFY hDevNotify;
    DEV_BROADCAST_DEVICEINTERFACE NotifacationFiler;
    ZeroMemory(&NotifacationFiler,sizeof(DEV_BROADCAST_DEVICEINTERFACE));
    NotifacationFiler.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
    NotifacationFiler.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;

    for(int i=0;i<sizeof(GUID_DEVINTERFACE_LIST)/sizeof(GUID);i++)
    {
        NotifacationFiler.dbcc_classguid = GUID_DEVINTERFACE_LIST[i];//GetCurrentUSBGUID();//m_usb->GetDriverGUID();
        hDevNotify = RegisterDeviceNotification((HANDLE)this->winId(),&NotifacationFiler,DEVICE_NOTIFY_WINDOW_HANDLE);
        if(!hDevNotify)
        {
            DWORD Err = GetLastError();
            qDebug() << "注册失败" <<endl;
        }
        //else
    }
#endif

   // on_btnOpen_clicked();

}
void MainWindow::readyRead()
{
    QByteArray buffer;
#ifdef SERIALPORT_V2_ENBALE

#else
    buffer = mSerialPort.readAll();
#endif
    mByteSendData=buffer;
    QString info;
    QString tmpStr;
    QString timeStr = "";
    //m_rxCnt += buffer.size();
    //m_stsRx->setText("RX: " + QString::number(m_rxCnt));

    QDateTime dateTime(QDateTime::currentDateTime());
    timeStr = "[" + dateTime.toString(" HH:mm:ss.zzz") + "] ";


    if (m_recvHex == 1)
    {
        info = buffer.toHex(' ').data();
        for (int i = 0; i < buffer.size(); i++)
        {
            tmpStr.sprintf("%02x ", buffer.at(i));
            qDebug() << buffer.at(i);
            info.append(tmpStr);
        }
    }
    else
    {
        info = QString(buffer);
    }
    //ui->textBrowser_3->clear();
    ui->textBrowser_3->append(timeStr + info);
    // TODO
    // 似乎直接用QByteArray无法直接取真正的值
    // 这里先转为数组，再判断，需要优化
    char *data = (char*)buffer.data();
    uint8_t buf[255] = {0};
    m_rxCnt+=buffer.size();
    if(buffer.contains("jw"))
    {
        //for (int i = 0; i < buffer.size(); i++)
        if(buffer.size()>5)
        {
           buf[0]=buffer.at(2)-48;
           buf[1]=buffer.at(3)-48;
           buf[2]=buffer.at(4)-48;
           //qDebug()<<"接收正确帧"<<int(buf[0]*100+buf[1]*10+buf[2]);
        }
        //解析接收数据

    }else{
         //qDebug()<<"接收错误帧";
    }


    // 根据值判断做逻辑处理，可做成函数
    if (buf[0] == 0xaa && buf[1] == 0x55)
    {

    }

    //mSerialPort.clear();
}

void MainWindow::on_deviceChanged(int flag)
{
    if (flag == 1)
    {
        foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            if (-1 == ui->comboBox_7->findText(info.portName()))
                ui->comboBox_7->addItem(info.portName());
        }
    }
    else
    {
        //mSerialPort.close();
        ui->pushButton_7->setText(tr("打开串口"));
        //ui->pushButton_7->setIcon(QIcon(":images/notopened.ico"));
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //CreateAnimation(this);

    QDateTime time=QDateTime::currentDateTime();
    timer=new QTimer(this);

    //setMinimumSize(1737,931);
    //setMaximumSize(1737,931);
    setWindowOpacity(0.90);
    this->setWindowTitle(tr("Blutooth_Tools"));
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
    //create serial port

    ui->setupUi(this);

    /************************************************************/
#if  0
     QBluetoothDeviceDiscoveryAgent *discoveryAgent;
     discoveryAgent = new QBluetoothDeviceDiscoveryAgent;
     connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(discoverBlueTooth(QBluetoothDeviceInfo)));
     connect(discoveryAgent, SIGNAL(finished()), this, SLOT(discoveryFinished()));
     discoveryAgent->start();
#endif
     /************************************************************/



    ui->dial->setMinimum(0);
    ui->dial->setMaximum(255);
    ui->dial->setNotchTarget(1);
    ui->dial->setNotchesVisible(true);
    ui->dial->setValue(0x26);
    ui->lcdNumber->display(0x26);

    ui->dial_2->setMinimum(0);
    ui->dial_2->setMaximum(255);
    ui->dial_2->setNotchTarget(1);
    ui->dial_2->setNotchesVisible(true);
    ui->dial_2->setValue(0x26);
    ui->lcdNumber_2->display(0x26);

    ui->dial_3->setMinimum(0);
    ui->dial_3->setMaximum(255);
    ui->dial_3->setNotchTarget(1);
    ui->dial_3->setNotchesVisible(true);
    ui->dial_3->setValue(0x26);
    ui->lcdNumber_3->display(0x26);

    ui->dial_4->setMinimum(0);
    ui->dial_4->setMaximum(255);
    ui->dial_4->setNotchTarget(1);
    ui->dial_4->setNotchesVisible(true);
    ui->dial_4->setValue(0x26);
    ui->lcdNumber_4->display(0x26);

    ui->dial_9->setMinimum(0);
    ui->dial_9->setMaximum(255);
    ui->dial_9->setNotchTarget(1);
    ui->dial_9->setNotchesVisible(true);
    ui->dial_9->setValue(80);

    ui->dial_10->setMinimum(0);
    ui->dial_10->setMaximum(255);
    ui->dial_10->setNotchTarget(1);
    ui->dial_10->setNotchesVisible(true);
    ui->dial_10->setValue(80);

    ui->dial_11->setMinimum(0);
    ui->dial_11->setMaximum(255);
    ui->dial_11->setNotchTarget(1);
    ui->dial_11->setNotchesVisible(true);
    ui->dial_11->setValue(80);

    ui->verticalSlider_2->setMinimum(0);
    ui->verticalSlider_2->setMaximum(100);
    ui->verticalSlider_2->setSingleStep(10);
    ui->verticalSlider_2->setTickPosition(QSlider::TicksLeft);

    ui->verticalSlider_3->setMinimum(0);
    ui->verticalSlider_3->setMaximum(100);
    ui->verticalSlider_3->setSingleStep(10);
    ui->verticalSlider_3->setTickPosition(QSlider::TicksLeft);

    ui->verticalSlider_4->setMinimum(0);
    ui->verticalSlider_4->setMaximum(100);
    ui->verticalSlider_4->setSingleStep(10);
    ui->verticalSlider_4->setTickPosition(QSlider::TicksLeft);


    ui->verticalSlider_5->setMinimum(0);
    ui->verticalSlider_5->setMaximum(100);
    ui->verticalSlider_5->setSingleStep(10);
    ui->verticalSlider_5->setTickPosition(QSlider::TicksLeft);

    ui->progressBar->setMaximum(1000);
    ui->progressBar->setRange(0,1000);

    ui->progressBar_3->setMaximum(100);
    ui->progressBar_3->setMinimum(0);
    ui->progressBar_4->setMaximum(100);
    ui->progressBar_4->setMinimum(0);
    ///////////////////////////////////////////////////
    /// \brief connect
    ///
    CreateBlackImage();
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(LableTextShow()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(LableTextShow()));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(LableTextShow()));

    //plot an image draw

    const QAudioDeviceInfo inputDevice = QAudioDeviceInfo::defaultInputDevice();
    if (inputDevice.isNull()) {
        QMessageBox::warning(nullptr, "audio",
                             "There is no audio input device available.");
    }

    QPalette pal(ui->widget->palette());

    //设置背景黑色
    pal.setColor(QPalette::Background, Qt::black);
    ui->widget->setAutoFillBackground(true);
    ui->widget->setPalette(pal);
    ui->widget->show();
    plot=new Plothjw(inputDevice,ui->widget);


   // m_file =new FileProtocolParsehjw;

    CreatePlot();

    //CreatWaveplot();//cancel by hjw when 10-27

    CreateProductPlot();

    //CreateSerialportWindow();
#ifdef SERIALPORT_V2_ENBALE
    CreateSerialPro();
#else
    #if 0
        m_serial->moveToThread(&mainThread);
        connect(&mainThread,&QThread::finished,m_serial,&QObject::deleteLater);
        connect(this,&MainWindow::serialDataSend,m_serial,&jwSerialThread::doDataSend);
        //connect(&mSerialPort,&QSerialPort::readyRead,m_serial,&jwSerialThread::doDataReceive);
        connect(m_serial,&jwSerialThread::sendResulttoGUI,this,&MainWindow::on_serial_show);
        mainThread.start();
    #endif
#endif
      ui->checkRecHexBox->show();
      ui->checkSendHexBox->show();

      QString cpu=lincese.getCpuName();
      ui->textBrowser_7->append(QString("CPU:")+cpu);
      ui->textBrowser_7->append(QString("未加密硬盘序号:")+lincese.getDiskNum());
      ui->textBrowser_7->append(QString("网卡:")+lincese.getWMIC("true"));
      ui->textBrowser_7->append(QString("设计:jinwen"));
      ui->textBrowser_7->append(QString("联系:Email--1044929595@qq.com"));

      //创建opengl
      CreateOpenGL(this);

    QGraphicsDropShadowEffect *shadowEffect1 = new QGraphicsDropShadowEffect(this);
    shadowEffect1->setOffset(5, 5);
    shadowEffect1->setColor(QColor(143, 43, 43));
    shadowEffect1->setBlurRadius(8);

    QGraphicsDropShadowEffect *shadowEffect2 = new QGraphicsDropShadowEffect(this);
    shadowEffect2->setOffset(5, 5);
    shadowEffect2->setColor(QColor(143, 23, 143));
    shadowEffect2->setBlurRadius(8);

    QGraphicsDropShadowEffect *shadowEffect3 = new QGraphicsDropShadowEffect(this);
    shadowEffect3->setOffset(5, 5);
    shadowEffect3->setColor(QColor(143, 143, 43));
    shadowEffect3->setBlurRadius(8);

    ui->pushButton_19->setGraphicsEffect(shadowEffect1);

    ui->pushButton_20->setGraphicsEffect(shadowEffect2);

    ui->pushButton_21->setGraphicsEffect(shadowEffect3);

    //创建雷达
    CreateRadarScanning(this);

    //创建单元测试
    //mtestNoudle=new TestModule;
    //mtestNoudle->setWindowTitle(tr("TesrModle"));
}



void MainWindow::discoveryFinished()
{
    qDebug()<<"discoveryFinished";
    static QString serviceUuid("00001101-0000-1000-8000-00805F9B34FB");
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    socket->connectToService(QBluetoothAddress(BTaddress), QBluetoothUuid(serviceUuid),QIODevice::ReadWrite);
    connect(socket,SIGNAL(readyRead()), this, SLOT(readBluetoothDataEvent()));
    connect(socket,SIGNAL(connected()), this, SLOT(bluetoothConnectedEvent()));
\
}

void MainWindow::discoverBlueTooth(QBluetoothDeviceInfo info)
{
    QString label = QString("%1 %2").arg(info.address().toString()).arg(info.name());
     if(info.name()=="HC-06")
     {
         BTaddress = info.address().toString();
     }
     qDebug()<<label;
}

void MainWindow::readBluetoothDataEvent()
{
   char data[100];
   qint64 len = socket->read((char *)data, 100);

   QByteArray qa2((char*)data,len);
   QString qstr(qa2.toHex());//
   qDebug()<<"----"<<qstr.toUpper();
}



void MainWindow::bluetoothDataSend(QString str)
{
    QByteArray arrayData;
    arrayData = str.toUtf8();
    socket->write(arrayData);
}

// 连接成功的事件中添加一行发送数据：
void MainWindow::bluetoothConnectedEvent()
{
    qDebug()<<"bluetoothConnectedEvent";
    bluetoothDataSend("hellow bluetooth");
}



void MainWindow::CreatePlot(void)
{
    #if 0
    ui->serial_plot->addGraph(ui->serial_plot->yAxis, ui->serial_plot->xAxis);
    ui->serial_plot->addGraph();
    ui->serial_plot->addGraph();
    ui->serial_plot->addGraph();

    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    ui->serial_plot->legend->setFont(legendFont);
    ui->serial_plot->legend->setBrush(QBrush(QColor(255,255,255,230)));


   QPen pen;
   pen.setWidth(2);
   pen.setStyle(Qt::PenStyle::DashLine);
   pen.setColor(Qt::yellow);

   ui->serial_plot->setLocale(QLocale(QLocale::English, QLocale::China)); // period as decimal separator and comma as thousand separator
   ui->serial_plot->legend->setVisible(true);

    ui->serial_plot->graph(1)->setPen(pen);
    ui->serial_plot->graph(0)->setPen(QPen(QColor(255, 100, 0)));
    ui->serial_plot->graph(1)->setPen(QPen(QColor(0, 220, 0)));
    ui->serial_plot->graph(2)->setPen(QPen(QColor(12, 0, 200)));
    ui->serial_plot->graph(3)->setPen(QPen(QColor(200, 153, 200)));



    //ui->serial_plot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->serial_plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    ui->serial_plot->graph(0)->setName("Left maxwell function");
    ui->serial_plot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsImpulse);
    ui->serial_plot->graph(0)->setName(tr("参数1"));

    //ui->serial_plot->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->serial_plot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
    ui->serial_plot->graph(1)->setLineStyle(QCPGraph::LineStyle::lsLine);
    ui->serial_plot->graph(1)->setName(tr("参数2"));


    //ui->serial_plot->graph(2)->setLineStyle(QCPGraph::lsNone);
    ui->serial_plot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 2));
    ui->serial_plot->graph(2)->setLineStyle(QCPGraph::LineStyle::lsLine);
    ui->serial_plot->graph(2)->setName(tr("参数3"));

    ui->serial_plot->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 2));
    ui->serial_plot->graph(3)->setLineStyle(QCPGraph::LineStyle::lsLine);
    ui->serial_plot->graph(3)->setName(tr("参数4"));


    //设置轴同步
     ui->serial_plot->graph(3)->rescaleAxes(true);
     ui->serial_plot->graph(2)->rescaleAxes(true);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");

     //ui->serial_plot->xAxis->ticker()->setTickCount(11);//11个主刻度
     //ui->serial_plot->xAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssReadability);//可读性优于设置

    ui->serial_plot->xAxis->setTicker(timeTicker);
    ui->serial_plot->xAxis->setLabel("- - - - - - - - - - - - - - - - - - - -调试时间- - - - - - - - - - - - - - - - - - -");
    //ui->serial_plot->xAxis->setTickLabelRotation(35);//旋转

    ui->serial_plot->axisRect()->setupFullAxesBox();
    ui->serial_plot->yAxis->setRange(-10, 500);
    ui->serial_plot->yAxis->setLabel("- - - - - -压感信号- - - - - - -");





    ui->serial_plot->axisRect()->setBackgroundScaled(true);
    ui->serial_plot->axisRect()->setBackgroundScaledMode(Qt::AspectRatioMode::IgnoreAspectRatio);
    ui->serial_plot->axisRect()->setBackground(QPixmap(":/Image/BKco.jpeg"));
    //ui->serial_plot->setBackground(QColor(255,255,255));

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->serial_plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->serial_plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->serial_plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->serial_plot->yAxis2, SLOT(setRange(QCPRange)));
    dataTimer= new QTimer(this);
    connect(dataTimer, SIGNAL(timeout()),this, SLOT(realtimeDataSlot()));
    dataTimer->start(100);

    #else
    ui->serial_plot->addGraph(ui->serial_plot->yAxis, ui->serial_plot->xAxis);
    ui->serial_plot->addGraph();
    ui->serial_plot->addGraph();
    ui->serial_plot->addGraph();

    ui->serial_plot->legend->setVisible(true);
    ui->serial_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->serial_plot->axisRect()->setupFullAxesBox();
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(8); // and make a bit smaller for legend
    ui->serial_plot->legend->setFont(legendFont);
    ui->serial_plot->legend->setBrush(QBrush(QColor(255,255,255,230)));

    QPen pen;
    pen.setWidth(1);
    pen.setStyle(Qt::PenStyle::DashLine);
    pen.setColor(Qt::yellow);

    ui->serial_plot->setLocale(QLocale(QLocale::English, QLocale::China)); // period as decimal separator and comma as thousand separator
    ui->serial_plot->legend->setVisible(true);

    //ui->serial_plot->graph(1)->setPen(pen);
    ui->serial_plot->graph(0)->setPen(QPen(QColor(120, 255, 12)));
    ui->serial_plot->graph(0)->setBrush(QColor(120,255,12,40));

    ui->serial_plot->graph(1)->setPen(QPen(QColor(0, 220, 0)));
    ui->serial_plot->graph(1)->setBrush(QColor(0, 220, 0,40));

    ui->serial_plot->graph(2)->setPen(QPen(QColor(12, 0, 200)));
    ui->serial_plot->graph(2)->setBrush(QColor(12, 0, 200,40));

    ui->serial_plot->graph(3)->setPen(QPen(QColor(12, 110, 200)));
    ui->serial_plot->graph(3)->setBrush(QColor(12, 110, 200,40));



    //ui->serial_plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->serial_plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
    ui->serial_plot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsLine);
    ui->serial_plot->graph(0)->setName(tr("参考轴"));

    //ui->serial_plot->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->serial_plot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
    ui->serial_plot->graph(1)->setLineStyle(QCPGraph::LineStyle::lsLine);
    ui->serial_plot->graph(1)->setName(tr("轴1"));


    //ui->serial_plot->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->serial_plot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
    ui->serial_plot->graph(2)->setLineStyle(QCPGraph::LineStyle::lsLine);
    ui->serial_plot->graph(2)->setName(tr("轴2"));

    ui->serial_plot->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
    ui->serial_plot->graph(3)->setLineStyle(QCPGraph::LineStyle::lsLine);
    ui->serial_plot->graph(3)->setName(tr("轴3"));

 

    //设置轴同步
    for(int i=0;i<4;i++){
      ui->serial_plot->graph(i)->rescaleAxes(true);
    }
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");

     //ui->serial_plot->xAxis->ticker()->setTickCount(11);//11个主刻度
     //ui->serial_plot->xAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssReadability);//可读性优于设置
    ui->serial_plot->xAxis->setTicker(timeTicker);
    ui->serial_plot->xAxis->setLabel("- - - - - - - - - - - - - - - - - - - -调试时间- - - - - - - - - - - - - - - - - - -");
    //ui->serial_plot->xAxis->setTickLabelRotation(35);//旋转
    ui->serial_plot->axisRect()->setupFullAxesBox();
    ui->serial_plot->yAxis->setRange(-30, 500);
    ui->serial_plot->yAxis->setLabel("- - - - - -压感信号- - - - - - -");
    ui->serial_plot->axisRect()->setBackgroundScaled(true);
    ui->serial_plot->axisRect()->setBackgroundScaledMode(Qt::AspectRatioMode::IgnoreAspectRatio);
    ui->serial_plot->axisRect()->setBackground(QPixmap(":/Image/BKco.jpeg"));

    //ui->serial_plot->setBackground(QColor(255,255,255));
    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->serial_plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->serial_plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->serial_plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->serial_plot->yAxis2, SLOT(setRange(QCPRange)));
    dataTimer= new QTimer(this);
    connect(dataTimer, SIGNAL(timeout()),this, SLOT(realtimeDataSlot()));
    dataTimer->start(100);
    #endif
}

void MainWindow::CreateProductPlot(void)
{

    ui->graph_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    QString demoName = "BluetoothAudioData";

    ui->graph_plot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    ui->graph_plot->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    ui->graph_plot->legend->setFont(legendFont);
    ui->graph_plot->legend->setBrush(QBrush(Qt::white));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    //ui->graph_plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    ui->graph_plot->yAxis->setRange(-30, 500);
    // setup for graph 0: key axis left, value axis bottom
    // will contain left maxwell-like function
    ui->graph_plot->addGraph(ui->graph_plot->xAxis, ui->graph_plot->yAxis);
    ui->graph_plot->graph(0)->setPen(QPen(Qt::darkGray));
    //ui->graph_plot->graph(0)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
    ui->graph_plot->graph(0)->setLineStyle(QCPGraph::lsImpulse);
    //ui->graph_plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
    ui->graph_plot->graph(0)->setName("音频");

    // setup for graph 1: key axis bottom, value axis left (those are the default axes)
    // will contain bottom maxwell-like function with error bars
    ui->graph_plot->addGraph();
    ui->graph_plot->graph(1)->setPen(QPen(Qt::yellow));
    //ui->graph_plot->graph(1)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // same fill as we used for graph 0
    ui->graph_plot->graph(1)->setLineStyle(QCPGraph::lsImpulse);
    //ui->graph_plot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
    ui->graph_plot->graph(1)->setName("FFT");
    //QCPErrorBars *errorBars = new QCPErrorBars(ui->graph_plot->xAxis, ui->graph_plot->yAxis);
    //errorBars->removeFromLegend();
    //errorBars->setDataPlottable(ui->graph_plot->graph(1));


    // setup for graph 2: key axis top, value axis right
    // will contain high frequency sine with low frequency beating:
    //ui->graph_plot->addGraph(ui->graph_plot->xAxis2, ui->graph_plot->yAxis2);
    //ui->graph_plot->graph(2)->setPen(QPen(Qt::blue));
    //ui->graph_plot->graph(2)->setName("High frequency sine");

    // setup for graph 3: same axes as graph 2
    // will contain low frequency beating envelope of graph 2
    //ui->graph_plot->addGraph(ui->graph_plot->xAxis2, ui->graph_plot->yAxis2);
    QPen blueDotPen;
    blueDotPen.setColor(QColor(30, 100, 100, 150));
    blueDotPen.setStyle(Qt::DotLine);
    blueDotPen.setWidthF(4);
    //ui->graph_plot->graph(3)->setPen(blueDotPen);
    //ui->graph_plot->graph(3)->setName("Sine envelope");

    // setup for graph 4: key axis right, value axis top
    // will contain parabolically distributed data points with some random perturbance
    //ui->graph_plot->addGraph(ui->graph_plot->xAxis2, ui->graph_plot->yAxis2);
    //ui->graph_plot->graph(4)->setPen(QColor(50, 50, 50, 255));
    //ui->graph_plot->graph(4)->setLineStyle(QCPGraph::lsLine);
    //ui->graph_plot->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot, 4));
    //ui->graph_plot->graph(4)->setName("Some random data around\na quadratic function");

    // generate data, just playing with numbers, not much to learn here:
    QVector<double> x0(25), y0(25);
    QVector<double> x1(15), y1(15), y1err(15);
    QVector<double> x2(250), y2(250);
    QVector<double> x3(250), y3(250);
    QVector<double> x4(250), y4(250);
    for (int i=0; i<25; ++i) // data for graph 0
    {
      x0[i] = 3*i/25.0;
      y0[i] = qExp(-x0[i]*x0[i]*0.8)*(x0[i]*x0[i]+x0[i]);
    }
    for (int i=0; i<15; ++i) // data for graph 1
    {
      x1[i] = 3*i/15.0;;
      y1[i] = qExp(-x1[i]*x1[i])*(x1[i]*x1[i])*2.6;
      y1err[i] = y1[i]*0.25;
    }
    for (int i=0; i<250; ++i) // data for graphs 2, 3 and 4
    {
      x2[i] = i/250.0*3*M_PI;
      x3[i] = x2[i];
      x4[i] = i/250.0*100-50;
      y2[i] = qSin(x2[i]*12)*qCos(x2[i])*10;
      y3[i] = qCos(x3[i])*10;
      y4[i] = 0.01*x4[i]*x4[i] + 1.5*(rand()/(double)RAND_MAX-0.5) + 1.5*M_PI;
    }

    // pass data points to graphs:
    ui->graph_plot->graph(0)->setData(x0, y0);
    ui->graph_plot->graph(1)->setData(x1, y1);
    //errorBars->setData(y1err);
    //ui->graph_plot->graph(2)->setData(x2, y2);
    //ui->graph_plot->graph(3)->setData(x3, y3);
    //ui->graph_plot->graph(4)->setData(x4, y4);
    // activate top and right axes, which are invisible by default:
    ui->graph_plot->xAxis2->setVisible(true);
    ui->graph_plot->yAxis2->setVisible(true);
    // set ranges appropriate to show data:
    //ui->graph_plot->xAxis->setRange(0, 2.7);
    //ui->graph_plot->yAxis->setRange(0, 2.6);



    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->graph_plot->xAxis->setTicker(timeTicker);

    // set pi ticks on top axis:
    ui->graph_plot->xAxis2->setTicker(QSharedPointer<QCPAxisTickerTime>(new QCPAxisTickerTime));
    // add title layout element:
    //ui->graph_plot->plotLayout()->insertRow(0);
    //ui->graph_plot->plotLayout()->addElement(0, 0, new QCPTextElement(ui->graph_plot, "K73测试项", QFont("sans", 12, QFont::Bold)));
    // set labels:
    ui->graph_plot->xAxis->setLabel("时间");
    //ui->graph_plot->yAxis->setLabel("Left axis label");
    //ui->graph_plot->xAxis2->setLabel("Top axis label");
    //ui->graph_plot->yAxis2->setLabel("Right axis label");
    // make ticks on bottom axis go outward:
    //ui->graph_plot->xAxis->setTickLength(0, 5);
    ui->graph_plot->xAxis->setSubTickLength(0, 3);
    // make ticks on right axis go inward and outward:

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->serial_plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->serial_plot->xAxis, SLOT(setRange(QCPRange)));
    connect(ui->serial_plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->serial_plot->yAxis, SLOT(setRange(QCPRange)));
    productdataTimer= new QTimer(this);
    connect(productdataTimer, SIGNAL(timeout()),this, SLOT(realtimeProductDataSlot()));
    productdataTimer->start(13);
}

void MainWindow::CreatWaveplot(void)
{

    // prepare data:
    QVector<double> x1(20), y1(20);
    QVector<double> x2(100), y2(100);
    QVector<double> x3(20), y3(20);
    QVector<double> x4(20), y4(20);
    for (int i=0; i<x1.size(); ++i)
    {
      x1[i] = i/(double)(x1.size()-1)*10;
      y1[i] = qCos(x1[i]*0.8+qSin(x1[i]*0.16+1.0))*qSin(x1[i]*0.54)+1.4;
    }
    for (int i=0; i<x2.size(); ++i)
    {
      x2[i] = i/(double)(x2.size()-1)*10;
      y2[i] = qCos(x2[i]*0.85+qSin(x2[i]*0.165+1.1))*qSin(x2[i]*0.50)+1.7;
    }
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i/(double)(x3.size()-1)*10;
      y3[i] = 0.05+3*(0.5+qCos(x3[i]*x3[i]*0.2+2)*0.5)/(double)(x3[i]+0.7)+qrand()/(double)RAND_MAX*0.01;
    }
    for (int i=0; i<x4.size(); ++i)
    {
      x4[i] = x3[i];
      y4[i] = (0.5-y3[i])+((x4[i]-2)*(x4[i]-2)*0.02);
    }

    // create and configure plottables:
    QCPGraph *graph1 =  ui->serial_plot->addGraph();
    graph1->setData(x1, y1);
    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graph1->setPen(QPen(QColor(120, 120, 120), 2));

    QCPGraph *graph2 =  ui->serial_plot->addGraph();
    graph2->setData(x2, y2);
    graph2->setPen(Qt::NoPen);
    graph2->setBrush(QColor(200, 200, 200, 20));
    graph2->setChannelFillGraph(graph1);

    QCPBars *bars1 = new QCPBars( ui->serial_plot->xAxis,  ui->serial_plot->yAxis);
    bars1->setWidth(9/(double)x3.size());
    bars1->setData(x3, y3);
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(10, 140, 70, 160));

    QCPBars *bars2 = new QCPBars( ui->serial_plot->xAxis,  ui->serial_plot->yAxis);
    bars2->setWidth(9/(double)x4.size());
    bars2->setData(x4, y4);
    bars2->setPen(Qt::DashDotLine);
    bars2->setBrush(QColor(10, 100, 50, 70));
    bars2->moveAbove(bars1);

    // move bars above graphs and grid below bars:
    ui->graph_plot->addLayer("abovemain",  ui->serial_plot->layer("main"), QCustomPlot::limAbove);
    ui->graph_plot->addLayer("belowmain",  ui->serial_plot->layer("main"), QCustomPlot::limBelow);
    graph1->setLayer("abovemain");
    ui->graph_plot->xAxis->grid()->setLayer("belowmain");
    ui->graph_plot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    ui->graph_plot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->graph_plot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->graph_plot->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->graph_plot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->graph_plot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->graph_plot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->graph_plot->xAxis->setTickLabelColor(Qt::white);
    ui->graph_plot->yAxis->setTickLabelColor(Qt::white);
    ui->graph_plot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->graph_plot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->graph_plot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->graph_plot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->graph_plot->xAxis->grid()->setSubGridVisible(true);
    ui->graph_plot->yAxis->grid()->setSubGridVisible(true);
    ui->graph_plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->graph_plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->graph_plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->graph_plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->graph_plot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->graph_plot->axisRect()->setBackground(axisRectGradient);

    ui->graph_plot->rescaleAxes();
    ui->graph_plot->yAxis->setRange(0, 2);
    ui->graph_plot->replot();
    ui->graph_plot->show();
}


void MainWindow::realtimeProductDataSlot(void)
{
    static QTime time(QTime::currentTime());
    double key = time.elapsed()/5000.0;

    ui->graph_plot->graph(0)->addData(key,qrand()%200);
    ui->graph_plot->graph(1)->addData(key,qrand()%15);
    //ui->graph_plot->graph(3)->addData(key,qrand()%6);
    //ui->graph_plot->graph(4)->addData(key,qrand()%5);

    ui->graph_plot->xAxis->setRange(key, 8, Qt::AlignTrailing);
    ui->graph_plot->xAxis2->setRange(key, 8, Qt::AlignTrailing);
    ui->graph_plot->replot();
}

void MainWindow::realtimeDataSlot()
{
#if 0
  double plotData;
  bool ok;
  static QTime time(QTime::currentTime());
  // calculate two new data points:
  double key = time.elapsed()/300.0; // time elapsed since start of demo, in seconds
  static double lastPointKey = 0;
  ////////////////////////////////////////////////////////////////////
  char *data = (char*)mByteSendData.data();
  uint8_t buf[255] = {0};
  m_rxCnt+=mByteSendData.size();
 // qDebug()<<"wqw"<<mByteSendData;

  {

      if(mByteSendData.size()>5)
      {
         buf[0]=32;//mByteSendData.at(2)-48;
         buf[1]=mByteSendData.at(0);
         buf[2]=mByteSendData.at(1);
         plotData=double(buf[0]*100+buf[1]*10+buf[2]);
         qDebug()<<"接收正确帧"<<int(buf[0]*100+buf[1]*10+buf[2]);
         ui->serial_plot->graph(0)->addData(key,plotData);
      }
      //解析接收数据
  }
  ////////////////////////////////////////////////////////////////////

  //if (key-lastPointKey > 0.100) // at most add point every 2 ms
  {
    ui->serial_plot->replot();
    //plotData=mByteSendData.toDouble(&ok);
    //ui->serial_plot->yAxis->setRange(double(-(plotData+300)), double(plotData+300));
    //ui->serial_plot->graph(0)->addData(key,plotData);
    lastPointKey = key;

  }

#ifdef  SERIALPORT_V2_ENBALE

#else
   mSerialPort.clear();
#endif
  mByteSendData.clear();


  // make key axis range scroll with the data (at a constant range size of 8):
  ui->serial_plot->xAxis->setRange(key, 8, Qt::AlignTrailing);
  ui->serial_plot->replot();
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
    #if 0
    ui->statusBar->showMessage(
          QString("%1 FPS, Total Data points: %2")
          .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
          .arg(ui->widget_2->graph(0)->data()->size()+ui->widget_2->graph(1)->data()->size())
          , 0);
    #endif
    lastFpsKey = key;
    frameCount = 0;
  }
#endif
}

void MainWindow::on_serial_show(QByteArray data)
{
    ui->textBrowser_3->append(data);
    qDebug()<<"on_serial_show"<<data;
}

bool MainWindow::find_SerialDevice(void)
{
    //查找可用的串口
    ui->comboBox_7->clear();

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        //mserialportList.append(info.portName()+info.description());
        qDebug()<<"串口名:"<<info.portName();
        qDebug()<<"描述信息:"<<info.description();
        qDebug()<<"制造商:"<<info.manufacturer();

        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->comboBox_7->addItem(serial.portName());
            #ifdef SERIALPORT_V2_ENBALE

            #else
                        serial.close();
            #endif
        }

    }

    //serialThread->run();

}

MainWindow::~MainWindow()
{
    //jwSerialThread->quit();
    //jwSerialThread->wait();

    delete timer;
    //delete jwSerialThread;
    delete m_file;

    //mainThread.quit();
    //mainThread.wait();

    if(portThread){
        portThread->quit();
    }
    portThread->wait();
    delete ui;
}
void MainWindow::ThreadTxt(int value)
{
    //ui->textEdit->append("run ...");
    ui->progressBar->setValue(value);
}

void MainWindow::timerUpdate()
{
    //static int cout=0;
    QDateTime time=QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label_2->setText(str);
}

void MainWindow::LableTextShow(void)
{
    pAnimation->start();
}



void MainWindow::on_pushButton_2_clicked()//导入
{
    m_file->FileOpen();
    QByteArray byte=m_file->FileRead();
    ui->textBrowser->append(byte);
}

void MainWindow::on_dial_valueChanged(int value)
{
     ui->lcdNumber->display(value);
}
void MainWindow::CreateBlackImage(void)
{
    pAnimation = new QPropertyAnimation(ui->label_3, "geometry");
    pAnimation->setDuration(1000);
    //pAnimation->setStartValue(QRect(10, 540, 1081, 171));
    //pAnimation->setEndValue(QRect(500, 200, 75, 25));
    pAnimation->setEasingCurve(QEasingCurve::SineCurve);
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_widget_windowIconTextChanged(const QString &iconText)
{
    QString str=iconText;
}

void MainWindow::on_dial_2_valueChanged(int value)
{
    ui->lcdNumber_2->display(value);
}

void MainWindow::on_dial_3_valueChanged(int value)
{
    ui->lcdNumber_3->display(value);
}

void MainWindow::on_dial_4_valueChanged(int value)
{
    ui->lcdNumber_4->display(value);
}

void MainWindow::on_pushButton_8_clicked()
{
     QStringList str;

     if(str.size()==0){
          ui->textBrowser_3->setText(tr("未发现"));
     }
     for(int i=0;i<str.size();i++){
        ui->textBrowser_3->setText(str[i]);
     }
    find_SerialDevice();
}
 void MainWindow::mainGUISendData(void)
 {
    QByteArray data;
    emit serialDataSend(data);
 }
void MainWindow::hanldeResults(QString &result)
{
    qDebug()<<result<<"线程ID:"<<QThread::currentThreadId();
}


void MainWindow::on_pushButton_7_clicked()
{
     qDebug()<<ui->comboBox_7->currentText();
     qDebug()<<ui->pushButton_7->text();
    if(ui->pushButton_7->text()==QString(tr("打开串口")))
    {
#if 0
        // 串口设备
        on_cbPortName_currentTextChanged(ui->comboBox_7->currentText());
        // 波特率（注：QtSerial支持的枚举不多，但设置了其它值也行）
        on_cbBaudrate_currentTextChanged(ui->comboBox_2->currentText());
        //设置数据位
        on_cbDatabit_currentTextChanged(ui->comboBox_4->currentText());
        //设置停止位
        on_cbStopbit_currentIndexChanged(ui->comboBox_3->currentIndex());
        //设置奇偶校验
        on_cbParity_currentIndexChanged(ui->comboBox_5->currentIndex());
        //设置流控制
        on_cbFlow_currentIndexChanged(ui->comboBox_6->currentIndex());
#endif


        showMessage("port opened.");

        ui->textBrowser_3->setText("串口已找到");
        ui->pushButton_7->setText(tr("关闭串口"));
        //mSerialPort.open(QIODevice::ReadWrite);
        //ui->pushButton_7->setIcon(QIcon(":images/opened.ico"));


#ifdef SERIALPORT_V2_ENBALE
        SerialObject->open(ui->comboBox_7->currentText(),115200);
        if(SerialObject->isOpne()){
            qDebug()<<"成功打开串口";
        }else{
            qDebug()<<"没有串口";
        }
#else
        if(!mSerialPort.open(QIODevice::ReadWrite) && !mSerialPort.isOpen())
        {
            //QMessageBox::about(NULL, tr("info"), tr("open port failed."));
            showMessage("open port failed.\n");
            //return;
        }
#endif
    }
    else
    {
#ifdef SERIALPORT_V2_ENBALE

#else
        mSerialPort.close();
#endif
        // SerialObject->open(ui->comboBox_7->currentText(),1152000);

        SerialObject->close();

        showMessage("port open.");
        ui->pushButton_7->setText(tr("打开串口"));
        //ui->pushButton_7->setIcon(QIcon(":images/notopened.ico"));
        qDebug()<<"serial open fiale";
    }
}

void MainWindow::serialport_receivedata()
{
    QByteArray info = mSerialPort.readAll();
    QByteArray hexData = info.toHex();
    //这里面的协议 你们自己定义就行  单片机发什么 代表什么 我们这里简单模拟一下
    if(hexData == "0x10000")
    {
        //do something
    }
    else if(hexData  == "0x100001")
    {
        //do something
    }
    qDebug()<<"\r\n hjw ------>";
}

void MainWindow::showMessage(const char* str)
{
    QString tmp = str;
    ui->statusbar->showMessage(tmp, 500);
}

void MainWindow::on_pushButton_9_clicked()
{
    Serialport_SendData();
}

void MainWindow::on_pushButton_10_clicked()
{
     ui->serialSendWindow->clear();
}



void MainWindow::on_btnOpen_clicked()
{


    if(ui->pushButton_7->text()==QString("打开串口"))
    {
        // 打开串口
        if(!mSerialPort.open(QIODevice::ReadWrite) && !mSerialPort.isOpen())
        {
            //QMessageBox::about(NULL, tr("info"), tr("open port failed."));
            showMessage("open port failed.\n");
            return;
        }

        showMessage("port opened.");
        ui->pushButton_7->setText(tr("关闭串口"));
        ui->pushButton_7->setIcon(QIcon(":images/opened.ico"));
    }
    else
    {
        //mSerialPort.close();

        showMessage("port closed.");
        ui->pushButton_7->setText(tr("打开串口"));
        ui->pushButton_7->setIcon(QIcon(":images/notopened.ico"));
    }
}

void MainWindow::on_btnSaveRecv_clicked()
{

}

void MainWindow::on_btnClearRecv_clicked()
{
    ui->textBrowser_3->clear();
}

void MainWindow::on_ckRecvHex_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        //m_recvHex = 1;
    }
    else if (arg1 == Qt::Unchecked)
    {
        //m_recvHex = 0;
    }
}

void MainWindow::on_ckTimestamp_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        //m_showTimestamp = 1;
    }
    else if (arg1 == Qt::Unchecked)
    {
        //m_showTimestamp = 0;
    }
}

void MainWindow::on_btnSend_clicked()
{
#if 0
    if (m_sendTimer)
    {

        if(ui->serialSendWindow->text()==QString("发送"))
        {
            if (m_sendTimerId == 0)
                m_sendTimerId = startTimer(ui->txtInterval->text().toInt());
            //ui->serialSendWindow->setText(tr("停止发送"));
        }
        else
        {
            if (m_sendTimerId)
            {
                killTimer(m_sendTimerId);
                m_sendTimerId = 0;
            }
            ui->btnSend->setText(tr("发送"));
        }
    }
    else
    {
        sendData();
    }
#endif
}



void MainWindow::Serialport_SendData(void)
{

#ifdef SERIALPORT_V2_ENBALE
	if(SerialObject->isOpne()){

	}else{
		showMessage("serial port not opened.");
		return ;
	}
#else
    if (!mSerialPort.isOpen())
    {
        showMessage("serial port not opened.");
        return;
    }
#endif

    QString sendStr = ui->serialSendWindow->toPlainText().toLatin1().toLower();
    QByteArray sendData;
    QString showStr;
 

    if (m_sendHex == 1)
    {
        hexStringToHexArray(sendStr, sendData);
    }
    else if (m_sendHex == 0)
    {
        sendData = sendStr.toLatin1();
    }
    if (m_sendNewline == 1)//回车
    {
        sendData.append(0x0d);
        sendData.append(0x0a);
    }
    qDebug() << sendData;
    m_txCnt += sendData.size();

#ifdef SERIALPORT_V2_ENBALE
    SerialObject->slot_writeBytes(sendData);
#else
    mSerialPort.write(sendData);
    qDebug()<<"发送中...";
#endif
}

void MainWindow::on_btnClearSend_clicked()
{

}

void MainWindow::sendHexData(QString& tips, uint8_t* ibuf, uint8_t ilen)
{
    QByteArray sendData;

    for (int i = 0; i < ilen; i++)
    {
        sendData[i] = ibuf[i];
    }

    QString tmp = sendData.toHex(' ').toLower();
    SerialObject->slot_writeBytes(sendData);

}

void MainWindow::on_chSendHex_stateChanged(int arg1)
{
    QString sendStr ;
    QByteArray sendData = sendStr.toLatin1();//ui->txtSend->toPlainText().toLatin1();
    QString tmpStr;
    QString showStr;
    if (arg1 == Qt::Checked)
    {
        m_sendHex = 1;
        showStr = sendData.toHex(' ').data();
		 qDebug()<<"发送十六进制打开";
    }
    else if (arg1 == Qt::Unchecked)
    {
        m_sendHex = 0;
        hexStringToString(sendStr, showStr); // 用string来转
        qDebug()<<"发送十六进制关闭";
    }
}

void MainWindow::on_ckSendTimer_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        m_sendTimer = 1;
    }
    else if (arg1 == Qt::Unchecked)
    {
        m_sendTimer = 0;
        if (m_sendTimerId)
        {
            killTimer(m_sendTimerId);
            m_sendTimerId = 0;
           // ui->serialSendWindow->setText("发送");
        }
    }
}


void MainWindow::on_chSendNewline_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        m_sendNewline = 1;
    }
    else if (arg1 == Qt::Unchecked)
    {
        m_sendNewline = 0;
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->textBrowser_3->clear();
}

void MainWindow::on_comboBox_7_activated(const QString &arg1)
{

}

void MainWindow::on_textBrowser_3_anchorClicked(const QUrl &arg1)
{
    if(SerialObject!=nullptr){
        qDebug()<<"asas"<<SerialObject->bytepub;
    }
}

void MainWindow::on_checkSendHexBox_stateChanged(int arg1)
{
    m_sendHex=m_sendHex?0:1;
    qDebug()<<"m_sendHex"<<m_sendHex;
}

void MainWindow::on_checkRecHexBox_stateChanged(int arg1)
{
    m_recvHex=m_recvHex?0:1;
    qDebug()<<"m_recvHex"<<m_recvHex;
}

void MainWindow::on_dial_9_valueChanged(int value)
{
  m_pressSurenValue=value;
  ui->lcdNumber_19->display(value);
}

void MainWindow::on_dial_9_actionTriggered(int action)
{

}

void MainWindow::on_dial_9_rangeChanged(int min, int max)
{

}

void MainWindow::on_dial_rangeChanged(int min, int max)
{

}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_radioButton_2_clicked()
{

}

bool MainWindow::CreateOpenGL(QObject *)
{

    mopengl =new  GLWidget(ui->openGLWidget);
    return false;
}

static bool showstatus=false;
void MainWindow::on_pushButton_18_clicked()
{
    if(false==showstatus){

        mtestNoudle->show();
    }
    else{
    mtestNoudle->hide();
    }
     //QMessageBox::information(this,QString::fromUtf8("提示"),QString::fromUtf8("选择文件失败无路径！"),"OK");
     showstatus=showstatus==true?false:true;
}

void MainWindow::addAnimationWidget(QSequentialAnimationGroup *Animation,QPushButton *widget)
{
    int Durtime = 200;
    int startX = 600;
    if(!widget->isHidden())
    {
        QPropertyAnimation *pScaleAnimation = new QPropertyAnimation(widget, "pos");
        pScaleAnimation->setDuration(Durtime);
        pScaleAnimation->setStartValue(QPoint(200, widget->y()));
        pScaleAnimation->setEndValue(QPoint(widget->x(),widget->y()));
        pScaleAnimation->setEasingCurve(QEasingCurve::Linear);
        Animation->addAnimation(pScaleAnimation);
        widget->move(startX,widget->y());
    }
}
void MainWindow::on_currentChanged(QSequentialAnimationGroup *Animation,int indexs)
{
    if(Animation->state()==QSequentialAnimationGroup::Running){
        Animation->pause();
        Animation->resume();
        return;
    }
    Animation->clear();
    if(indexs ==0)
    {
        //this->addAnimationWidget(Animation,ui->btn_1);
        //this->addAnimationWidget(Animation,ui->btn_2);
        //this->addAnimationWidget(Animation,ui->btn_3);
        //this->addAnimationWidget(Animation,ui->btn_4);
    }
    else
    {
        //this->addAnimationWidget(Animation,ui->btn_5);
        //this->addAnimationWidget(Animation,ui->btn_6);
        //this->addAnimationWidget(Animation,ui->btn_7);
        //this->addAnimationWidget(Animation,ui->btn_8);
    }
    Animation->start();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if((index==0)||(index==1)){

        QWidget *widget0  = ui->tabWidget->widget(0);
        QWidget *widget1  = ui->tabWidget->widget(1);

        QPixmap pixmap0 = QPixmap::grabWidget(widget0);//
        QPixmap pixmap1 = QPixmap::grabWidget(widget1);//

        QPixmap *pixmap  = new QPixmap(pixmap0.width() + pixmap1.width()  ,  pixmap0.height());

        QImage image(pixmap0.width() + pixmap1.width() , pixmap0.height(),QImage::Format_ARGB32);
        image.fill(QColor(Qt::black));

        QPainter p;
        //p.setRenderHint(QPainter::Antialiasing, true);//
        p.begin(&image);
        QBrush brush(QColor(255, 255, 0), Qt::Dense4Pattern);
        p.setBrush(brush);
        QPen pen ;
        pen.setColor(QColor(Qt::red));
        p.setPen(pen);
        p.drawPixmap(0,0,pixmap0);
        p.drawPixmap(pixmap0.width(),0,pixmap1);
        p.end();


        QLabel *animationWidget = new QLabel(ui->tabWidget);
        animationWidget->setPixmap(QPixmap::fromImage(image));
        QTabBar *bar = ui->tabWidget->tabBar();
        QSize size1 = bar->size();
        QSize size2 =  ui->tabWidget->size();

        animationWidget->show();
        animationWidget->raise();
        animationWidget->setGeometry(1,1,pixmap0.width(),pixmap0.height());

        if(index == 1)
        {
        QPropertyAnimation *move1 = new QPropertyAnimation(animationWidget,"geometry" );
        move1->setDuration(700);
        move1->setStartValue(QRect(  0,bar->size().height(),pixmap0.width(),pixmap0.height())  );
        move1->setEndValue(QRect( -pixmap0.width(), bar->size().height() ,pixmap0.width()*2,pixmap0.height()  )  );
        move1->start();
        connect(move1, &QAbstractAnimation::finished, this, [=]() {
        delete animationWidget;
        delete move1;
        });
        }else{
        QPropertyAnimation *move1 = new QPropertyAnimation(animationWidget ,"geometry" );
        move1->setDuration(2000);
        move1->setStartValue(QRect(-pixmap0.width(),bar->size().height(),pixmap0.width()*2,pixmap0.height()));
        move1->setEndValue(QRect(0,bar->size().height(),pixmap0.width(),pixmap0.height()));
        move1->start();
        connect(move1, &QAbstractAnimation::finished, this, [=]() {
        delete animationWidget;
        delete move1;
        });
        }

    }
}


bool MainWindow::CreateRadarScanning(QObject *)
{
    mRadarScanning=new RadarScanning(ui->widget_2);
    ui->widget_2->show();
    //mRadarScanning->show();
    return false;
}
