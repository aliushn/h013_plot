QT       += core gui\
            charts \
            multimedia\
            serialport\
            printsupport\
            bluetooth\
            quick\
            qml\
            multimedia\
            network\
            axcontainer\
            opengl\
            printsupport\
            sql\
            ##mqtt\

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS\


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#LIBS += -L$$_PRO_FILE_PWD_/  -lhidapi


SOURCES += \
    appthreadhjw.cpp \
    enterwindow.cpp \
    fileprotocolparsehjw.cpp \
    jwAlgorithm/jwfft.cpp \
    jwDatabase/jwdatabase.cpp \
    jwRadarScanning/RadarScanning.cpp \
    jwserialthread.cpp \
    licensehjw.cpp \
    main.cpp \
    maintable.cpp \
    mainwindow.cpp \
    plothjw.cpp \
    testmodule.cpp \
    xyseriesiodevice.cpp\
    jwserial.cpp \
    jwplot/jwplot.cpp\
    qcustomplot.cpp\
    jwserialpro.cpp \
    waterprogressbar.cpp \
    bmachinecontrol.cpp \
    jwMusic/jwmusic.cpp \
    jwmqtt.cpp \
    glwidget.cpp




HEADERS += \
    appthreadhjw.h \
    enterwindow.h \
    fileprotocolparsehjw.h \
    jwAlgorithm/jwfft.h \
    jwDatabase/jwdatabase.h \
    jwRadarScanning/RadarScanning.h \
    jwserialthread.h \
    licensehjw.h \
    maintable.h \
    jwMusic/jwmusic.h \
    mainwindow.h\
    hidapi.h \
    plothjw.h \
    testmodule.h \
    xyseriesiodevice.h\
    jwserial.h \
    jwplot/jwplot.h\
    qcustomplot.h\
    jwserialpro.h \
    waterprogressbar.h \
    bmachinecontrol.h \
    jwmqtt.h \
    glwidget.h




FORMS += \
    enterwindow.ui \
    mainwindow.ui \
    testmodule.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    BP.qrc


DEFINES += QT_DEPRECATED_WARNINGS

win32: LIBS += -lSetupAPI -luser32


INCLUDEPATH +=C:\K73_QTSerial\HM013-PC-user\HM013-PC\FFTReal-2.11\
              $$PWD/ffmpeg/ffmpeg-4.0.2-win64-dev/include\
              $$PWD/ffmpeg/ffmpeg-4.0.2-win64-dev/include\
              D:\opencvlib\opencv\build\install\include\

             ## $$PWD/jwEigen/eigen-3.4.0/Eigen\



LIBS += -L$$PWD/ffmpeg/"ffmpeg-4.0.2-win64-dev/lib" -lavcodec \
        -L$$PWD/ffmpeg/"ffmpeg-4.0.2-win64-dev/lib" -lavdevice \
        -L$$PWD/ffmpeg/"ffmpeg-4.0.2-win64-dev/lib" -lavfilter \
        -L$$PWD/ffmpeg/"ffmpeg-4.0.2-win64-dev/lib" -lavformat \
        -L$$PWD/ffmpeg/"ffmpeg-4.0.2-win64-dev/lib" -lavutil \
        -L$$PWD/ffmpeg/"ffmpeg-4.0.2-win64-dev/lib" -lpostproc \
        -L$$PWD/ffmpeg/"ffmpeg-4.0.2-win64-dev/lib" -lswresample \
        -L$$PWD/ffmpeg/"ffmpeg-4.0.2-win64-dev/lib" -lswscale \
        D:\opencvlib\opencv\build\install\x64\mingw\staticlib\libopencv_*.a\
        D:\opencvlib\opencv\build\install\x64\mingw\staticlib\lib*.a\


###DISTFILES +=

