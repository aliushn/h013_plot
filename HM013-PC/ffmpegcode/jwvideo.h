#ifndef JWVIDEO_H
#define JWVIDEO_H

#include <QObject>
#include <QWidget>
#include "qthread.h"
#include <QMainWindow>

extern "C"{
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
    #include "libswscale/swscale.h"
    #include "libavdevice/avdevice.h"
}


class jwVideo:public QThread
{
public:
    jwVideo();
    void playvideo();

    void ReadjwDevice();
protected:
    void run();



private:
    QImage image;
    int lineSize[4];
    AVFormatContext *formatContext;
    AVCodecParameters *codecParameters;
    int videoIndex;
    AVCodecContext* codecContext;
    AVPacket *packet;
    AVFrame *frame;
    SwsContext *imgConvertContext;

};

#endif // JWVIDEO_H
