#include "mainwindow.h"
#include <QCryptographicHash>
#include <QApplication>
#include "qdebug.h"
#include "qsettings.h"
#include <QFile>
#include <QString>

#include "qstring.h"
#include "hidapi.h"
#include <QThread>
#include <enterwindow.h>
#include <QtMultimedia/QAudioDeviceInfo>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
//#include "usbhidhjw.h"
#include "jwblue.h"
#include <QMessageBox>
#include "bmachinecontrol.h"
#include <jwDatabase/jwdatabase.h>

#include "jwAlgorithm/jwfft.h"


#define printf qDebug
#define HKEY_CURRENT_USE_QT "HKEY_CURRENT_USER\\Software\\JW||TEST"


int main(int argc, char *argv[])
{

    QApplication sdk(argc, argv);

    QFile file(":black.qss"); // 指定路径
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            sdk.setStyleSheet(file.readAll());
            file.close();
    }
    EnterWindow enterw;
    enterw.show();
    MainWindow w;
    w.show();
    w.setWindowTitle("K73_xiaomi");

    //add
    QSettings setting(HKEY_CURRENT_USE_QT,QSettings::NativeFormat);
    //setting.setValue("name","jw");

    qDebug()<<setting.value("name","").toString();

    //setting.remove("name");

   return sdk.exec();
}
