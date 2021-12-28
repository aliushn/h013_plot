#ifndef JWSERIALPRO_H
#define JWSERIALPRO_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>
#include <QDebug>


class jwSerialPro :public QObject
{
    Q_OBJECT
public:
    explicit jwSerialPro(QObject *parent=0);
    ~jwSerialPro();

    void initConnect();
    bool isOpne();

    QSerialPort *serialport;
    //public members
    QByteArray bytepub;

signals:
    void signal_message(QString str);
    void signal_portstatuschange(bool flag);
    void signal_byteRead(QByteArray data);
    void signal_byteWrite(QByteArray data);
    void signal_deleteportobject();

public slots:
    void slot_readBytes();
    void slot_writeBytes(QByteArray data);
    void slot_process();
    void open(QString string ,qint32 baudrate);
    void close();

private:
    qint64 waitforReadReadTime=1000;//100
    qint64 waitforWriteTime=5;
};

#endif // JWSERIALPRO_H
