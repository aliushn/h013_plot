#include "jwvideo.h"
#include "qdebug.h"

#include <QTime>
#include <QTimer>

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavfilter/avfilter.h"
#include "libavformat/avformat.h"
#include "libavutil/avutil.h"
#include "libavutil/ffversion.h"
#include "libswresample/swresample.h"
#include "libswscale/swscale.h"
#include "libpostproc/postprocess.h"
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
#include "libavdevice/avdevice.h"
}


jwVideo::jwVideo()
{
    int ver_major,ver_minor,ver_micro;
    unsigned version=avcodec_version();
    ver_major = (version>>16)&0xff;
    ver_minor = (version>>8)&0xff;
    ver_micro = (version)&0xff;

    qDebug()<<"ffmpeg_version"<<version<<ver_major<<ver_minor<<ver_micro;\


}


void jwVideo::run()
{
#if 1
    //初始化
    char filePath[]       = "/home/jackey/Videos/Sample.mkv";//文件地址
    int  videoStreamIndex = -1;//视频流所在流序列中的索引
    int ret=0;//默认返回值

    //需要的变量名并初始化
    AVFormatContext *fmtCtx=NULL;
    AVPacket *pkt =NULL;
    AVCodecContext *codecCtx=NULL;
    AVCodecParameters *avCodecPara=NULL;
    AVCodec *codec=NULL;
    AVFrame *yuvFrame = av_frame_alloc();
    //
    do{
        fmtCtx=avformat_alloc_context();

        if((ret=avformat_open_input(&fmtCtx,filePath,NULL,NULL))!=0){
            qDebug()<<"as";
            break;
        }

    }while(0);
#endif
}



void Delay(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
#if 0
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
#endif
}


void jwVideo::playvideo()
{
#if 1
AVFormatContext    *pFormatCtx;
int                i, videoindex;
AVCodecContext    *pCodecCtx;
AVCodec            *pCodec;
AVFrame    *pFrame, *pFrameRGB;
unsigned char *out_buffer;
AVPacket *packet;
int ret, got_picture;
struct SwsContext *img_convert_ctx;

char filepath[] = "D:/TEST.mkv";
//初始化编解码库
av_register_all();//创建AVFormatContext对象，与码流相关的结构。
pFormatCtx = avformat_alloc_context();
//初始化pFormatCtx结构
if (avformat_open_input(&pFormatCtx, filepath, NULL, NULL) != 0){
    printf("Couldn't open input stream.\n");
    return ;
}
//获取音视频流数据信息
if (avformat_find_stream_info(pFormatCtx, NULL) < 0){
    printf("Couldn't find stream information.\n");
    return ;
}
videoindex = -1;
//nb_streams视音频流的个数，这里当查找到视频流时就中断了。
for (i = 0; i < pFormatCtx->nb_streams; i++)
    if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO){
        videoindex = i;
        break;
}
if (videoindex == -1){
    printf("Didn't find a video stream.\n");
    return ;
}
//获取视频流编码结构
pCodecCtx = pFormatCtx->streams[videoindex]->codec;
//查找解码器
pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
if (pCodec == NULL){
    printf("Codec not found.\n");
    return ;
}
//用于初始化pCodecCtx结构
if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0){
    printf("Could not open codec.\n");
    return ;
}
//创建帧结构，此函数仅分配基本结构空间，图像数据空间需通过av_malloc分配
pFrame = av_frame_alloc();
pFrameRGB = av_frame_alloc();
//创建动态内存,创建存储图像数据的空间
//av_image_get_buffer_size获取一帧图像需要的大小
out_buffer = (unsigned char *)av_malloc(av_image_get_buffer_size(AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height, 1));
av_image_fill_arrays(pFrameRGB->data, pFrameRGB->linesize, out_buffer,
    AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height, 1);

packet = (AVPacket *)av_malloc(sizeof(AVPacket));
//Output Info-----------------------------
printf("--------------- File Information ----------------\n");
//此函数打印输入或输出的详细信息
av_dump_format(pFormatCtx, 0, filepath, 0);
printf("-------------------------------------------------\n");
//初始化img_convert_ctx结构
img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt,
    pCodecCtx->width, pCodecCtx->height, AV_PIX_FMT_RGB32, SWS_BICUBIC, NULL, NULL, NULL);
//av_read_frame读取一帧未解码的数据
while (av_read_frame(pFormatCtx, packet) >= 0){
    //如果是视频数据
    if (packet->stream_index == videoindex){
        //解码一帧视频数据
        ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, packet);
        if (ret < 0){
            printf("Decode Error.\n");
            return ;
        }
        if (got_picture){
            sws_scale(img_convert_ctx, (const unsigned char* const*)pFrame->data, pFrame->linesize, 0, pCodecCtx->height,
                pFrameRGB->data, pFrameRGB->linesize);
            QImage img((uchar*)pFrameRGB->data[0],pCodecCtx->width,pCodecCtx->height,QImage::Format_RGB32);
            //ui->label->setPixmap(QPixmap::fromImage(img));

            Delay(40);
        }
    }
    av_free_packet(packet);
}
sws_freeContext(img_convert_ctx);
av_frame_free(&pFrameRGB);
av_frame_free(&pFrame);
avcodec_close(pCodecCtx);
avformat_close_input(&pFormatCtx);
#endif
}

void jwVideo::ReadjwDevice()
{
    avdevice_register_all();                                    //初始化所有设备
    formatContext=avformat_alloc_context();                     //分配format上下文
    AVInputFormat *inputFormat=av_find_input_format("gdigrab"); //寻找输入设备【gdigrab】
    AVDictionary* options = NULL;
    av_dict_set(&options,"framerate","60",0);                   //设置帧数为60
    if(avformat_open_input(&formatContext,"desktop",inputFormat,&options)){ //开启输入设备
        qDebug()<<"cant`t open input stream.";
        return ;
    }
    if(avformat_find_stream_info(formatContext,nullptr)){       //加载流中存储的信息
        qDebug()<<"can`t find stream information.";
        return ;
    }

    videoIndex=-1;                                              //寻找视频流
    for(uint i=0;i<formatContext->nb_streams;i++){
        if(formatContext->streams[i]->codecpar->codec_type==AVMEDIA_TYPE_VIDEO){
            videoIndex=i;
            break;
        }
    }
    if(videoIndex==-1){
        qDebug()<<"can`t find video stream.";
        return ;
    }
    codecParameters=formatContext->streams[videoIndex]->codecpar;
    codecContext=avcodec_alloc_context3(nullptr);
    avcodec_parameters_to_context(codecContext,codecParameters);
    AVCodec* codec=avcodec_find_decoder(codecParameters->codec_id);

    if(codec==nullptr){
        qDebug()<<"can`t find codec";
        return ;
    }
    if(avcodec_open2(codecContext,codec,nullptr)){
        qDebug()<<"can`t open codec";
        return ;
    }

    packet=av_packet_alloc();
    frame=av_frame_alloc();

    imgConvertContext=sws_getContext(codecParameters->width,codecParameters->height,codecContext->pix_fmt,codecParameters->width,codecParameters->height,AV_PIX_FMT_RGB24,SWS_BICUBIC,nullptr,nullptr,nullptr);
    image=QImage(codecParameters->width,codecParameters->height,QImage::Format_RGB888);
    av_image_fill_linesizes(lineSize,AV_PIX_FMT_RGB24,codecParameters->width);

#if 0
    QTimer *timer=new QTimer;           //定时刷新
    connect(timer,&QTimer::timeout,this,static_cast<void (QWidget::*)()>(&QWidget::repaint));
    timer->setInterval(20);
    timer->start();

    resize(codecParameters->width*0.6,codecParameters->height*0.6);
#endif
}

#if 0
void Widget::paintEvent(QPaintEvent *event)
{
    if(av_read_frame(formatContext,packet)){
        return ;
    }
    if(packet->stream_index==videoIndex){
        if(avcodec_send_packet(codecContext,packet))
            return;
        if(avcodec_receive_frame(codecContext,frame))
            return;
        uint8_t* dst[]={image.bits()};
        sws_scale(imgConvertContext,frame->data,frame->linesize,0,codecParameters->height,dst,lineSize);
        av_packet_unref(packet);                //清空数据包

        QPainter painter(this);
        painter.fillRect(rect(),image.scaled(width(),height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }
}
#endif



















