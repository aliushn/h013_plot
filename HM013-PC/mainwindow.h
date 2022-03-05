#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "appthreadhjw.h"
#include <QMainWindow>
#include <QPropertyAnimation>
#include "fileprotocolparsehjw.h"
#include <QFileDialog>
#include <QDir>
#include <QList>
#include "qlist.h"
#include "plothjw.h"
#include "jwserialthread.h"
#include <QThread>
#include <QTimer>
#include <QTime>

#include "qcustomplot.h"
#include <QThreadPool>
#include <QThread>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "jwserial.h"
#include "jwserialthread.h"
#include <callback.h>
#include <QBluetoothSocket>
#include <QBluetoothUuid>
#include <QBluetoothAddress>
#include <QIODevice>
#include <QBluetoothDeviceInfo>
#include <qbluetoothdevicediscoveryagent.h>
#include <QBluetoothLocalDevice>

#include <windows.h>
#include <WinUser.h>
#include <Dbt.h>
#include <devguid.h>
#include <SetupAPI.h>
#include <InitGuid.h>
#include <QMouseEvent>
#include <QByteArray>
#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <QDateTime>
#include "licensehjw.h"
#include "jwserialpro.h"

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <jwOpengl/glwidget.h>
#include <QSequentialAnimationGroup>

//创建雷达扫描
#include "jwRadarScanning/RadarScanning.h"
#include "testmodule.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


#define SERIALPORT_V2_ENBALE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void CreateSerialportWindow(void);
    void CreateBlackImage(void);
    void mainGUISendData(void);
    void CreatePlot(void);
    void CreatWaveplot(void);
    void CreateProductPlot(void);
    bool find_SerialDevice(void);
    void bluetoothDataSend(QString str);
    void Serialport_SendData(void);
    void stringTohexString(QString& str, QString& hexStr);
    int hexStringToString(QString& hexStr, QString& str);
    int hexStringToHexArray(QString& hexStr, QByteArray& arr);
    int hexArrayToString(QByteArray& hexArr, QString& str);

    
    //创建串口
    bool CreateSerialPro(void);
	void sendHexData(QString& tips, uint8_t* ibuf, uint8_t ilen);
    //创建动画
    bool CreateAnimation(QObject *);
    void addAnimationWidget(QSequentialAnimationGroup *Animation,QPushButton *widget);
    void on_currentChanged(QSequentialAnimationGroup *Animation,int indexs);
    //创建OPENGL
    bool CreateOpenGL(QObject *);
    //创建雷达
    bool CreateRadarScanning(QObject *);
signals:
    void serialDataSend(const QByteArray data);//通知串口接收数据
    void serialDataRead(void);
    //////////////////////////////////////////////////
    void sig_exit();
    void sig_deviceChanged(int flag);

public slots:
    void hanldeResults(QString &result);
    void on_serial_show(QByteArray data);//接收串口数据
    void readyRead();
    void on_deviceChanged(int flag);
    ///////////////////////////////////////////////////


private slots:
    void on_pushButton_2_clicked();

    void on_dial_valueChanged(int value);

    void on_pushButton_clicked();

    void timerUpdate(void);

    void LableTextShow(void);

    void on_widget_windowIconTextChanged(const QString &iconText);

    void ThreadTxt(int value);

    void on_dial_2_valueChanged(int value);

    void on_dial_3_valueChanged(int value);

    void on_dial_4_valueChanged(int value);

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void realtimeDataSlot();

    void realtimeProductDataSlot(void);

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    //////////////////////////////////////////////////////////
    void discoverBlueTooth(QBluetoothDeviceInfo info);
    void discoveryFinished();
    //void scanFinished();
    void readBluetoothDataEvent();
    void bluetoothConnectedEvent();

    void serialport_receivedata();

    void on_chSendNewline_stateChanged(int arg1);

    void on_pushButton_11_clicked();

    void on_comboBox_7_activated(const QString &arg1);

    //添加串口槽函数
    void slot_readByteshjw(QByteArray data);

    void on_textBrowser_3_anchorClicked(const QUrl &arg1);

    void on_checkSendHexBox_stateChanged(int arg1);

    void on_checkRecHexBox_stateChanged(int arg1);

    void on_dial_9_actionTriggered(int action);

    void on_dial_rangeChanged(int min, int max);

    void on_dial_9_rangeChanged(int min, int max);

    void on_dial_9_valueChanged(int value);

    void on_pushButton_3_clicked();

    void on_radioButton_2_clicked();
    void on_pushButton_18_clicked();


    void on_tabWidget_currentChanged(int index);

public :
    // 串口
    int m_pressMouse;
    QPoint m_startPos;
    QPoint m_windowPos;
    int m_recvHex=0;
    int m_sendHex=0;
    int m_sendTimer;
    int m_sendNewline;
    int m_sendTimerId;
    int m_rxCnt=0;
    int m_txCnt=0;
    // 状态栏相关

    void showMessage(const char* str);

    void on_btnOpen_clicked();

    void on_btnSaveRecv_clicked();

    void on_btnClearRecv_clicked();

    void on_ckRecvHex_stateChanged(int arg1);

    void on_ckTimestamp_stateChanged(int arg1);

    void on_btnSend_clicked();

    void on_btnClearSend_clicked();

    void on_chSendHex_stateChanged(int arg1);

    void on_ckSendTimer_stateChanged(int arg1);


private:
    QTimer *timer;
    Ui::MainWindow *ui;
    QPropertyAnimation   *pAnimation;
    ///////////////////////////////
    Plothjw              *plot;
    FileProtocolParsehjw *m_file;

    QTimer*         dataTimer;
    QTimer*         productdataTimer;
    /////////////////////////////////////////////
    QThreadPool     *pMainThread;

    QCustomPlot     *mCustombar;
    QString         serialportname;
    QStringList     mserialportList;

    QThread         mainThread;
    QThread         PlotThread;
    QSerialPort     mSerialPort;

    QByteArray       mByteSendData;
    QBluetoothLocalDevice *localDevice;
    QString BTaddress;		// 记录MAC地址
    QBluetoothSocket *socket;

    ///////////////////////////////////////////////////
    //创建串口
    QThread* portThread;
    jwSerialPro* SerialObject;

    ////////////////////////////////////////////////////
    //压感阀值
    int m_pressSurenValue=0;
    Licensehjw lincese;

    //创建opengl
    GLWidget *mopengl;

    //创建雷达扫描
    RadarScanning *mRadarScanning;

    //Ui::TestModule *testModuleUI;
    TestModule *mtestNoudle;
};
#endif // MAINWINDOW_H
