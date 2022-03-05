#include "jwserialpro.h"

#define __DEBUGx
jwSerialPro::jwSerialPro(QObject *parent):QObject(parent)
{
#ifdef __DEBUG
    qDebug()<<__FUNCTION__<<"thread:"<<QThread::currentThread();
#endif
}

jwSerialPro::~jwSerialPro()
{
    qDebug()<<"~jwSerialPro";
    emit signal_deleteportobject();
    close();
    delete this->serialport;
}

void jwSerialPro::slot_process()
{
#ifdef __DEBUG
    qDebug()<<__FUNCTION__<<"thread:"<<QThread::currentThread();
#endif
    this->serialport=new QSerialPort;
    initConnect();
}

void jwSerialPro::initConnect()
{
    connect(serialport,SIGNAL(readyRead()),this,SLOT(slot_readBytes()));
}

void jwSerialPro::close()
{
#ifdef __DEBUG
    qDebug()<<__FUNCTION__<<"thread:"<<QThread::currentThread();
#endif
    if(this->serialport->isOpen()){
       this->serialport->close();
    }
}

 void jwSerialPro::open(QString string ,qint32 baudrate)
 {
#ifdef __DEBUG
    qDebug()<<__FUNCTION__<<"thread:"<<QThread::currentThread();
#endif
    this->serialport->setPortName(string);
    this->serialport->setBaudRate(qint32(115200));//1152000
    this->serialport->setDataBits(QSerialPort::Data8);
    this->serialport->setStopBits(QSerialPort::OneStop);
    this->serialport->setParity(QSerialPort::NoParity);
    this->serialport->setFlowControl(QSerialPort::NoFlowControl);
    this->serialport->setReadBufferSize(50*1024*1024);
    if(this->serialport->open(QIODevice::ReadWrite)){
        emit signal_portstatuschange(true);
    }else{
        emit signal_portstatuschange(false);
        emit signal_message(QString("open failed: %d").arg(this->serialport->errorString()));
    }
 }

 void jwSerialPro::slot_readBytes()
 {
#ifdef __DEBUG
    qDebug()<<__FUNCTION__<<"thread:"<<QThread::currentThread();
#endif
    //if(serialport->waitForReadyRead(int(100))){
        QByteArray data=serialport->readAll();
        if(data.isEmpty()) return;
            emit signal_byteRead(data);
    //}
 }

void jwSerialPro::slot_writeBytes(QByteArray data)
{
#ifdef __DEBUG
    qDebug()<<__FUNCTION__<<"thread:"<<QThread::currentThread();
#endif
    qint64 ret=serialport->write(data);
    serialport->waitForBytesWritten(int(waitforWriteTime));

    if(ret==-1){
        emit signal_message(QString("send failed:%d").arg(this->serialport->errorString()));
    }else{
        emit signal_byteWrite(data);
    }
}

bool jwSerialPro::isOpne()
{
    return this->serialport->isOpen();
}
