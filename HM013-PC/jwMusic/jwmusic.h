#ifndef JWMUSIC_H
#define JWMUSIC_H

#include <QObject>
#include <QWidget>
#include <QThread>
#include <QObject>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QMutex>
#include <QByteArray>
#include <QMutexLocker>
#include <QDebug>


#define g_AudioPlayThread AudioPlayThread::getInstance()
class jwMusic:public QThread
{
    Q_OBJECT
public:
    static jwMusic* getInstance(void);
    jwMusic(QObject *parent = nullptr);
    ~jwMusic();

    //----------添加 关联相关
    void setCurrentBuffer(QByteArray  buffer);
    void addAudioBuffer(const char *pData,int len);
    void cleanAudioBuffer(void);

    //设置当前采样率、采样位数、通道数目
    void setCurrentSampleInfo(int sampleRate,int sampleSize,int channelCount);

    virtual void run(void) override;

    //获取当前所在位置
    int getCurrentBufferIndex(void);
    int getCurrentTime(void);

    //切换播放状态
    void playMusic(bool status);
    bool getPlayMusicStatus(void);
    void setCurrentVol(qreal vol);
    qreal getCurrentVol(void);

private:
    QAudioOutput *m_OutPut=nullptr;
    QIODevice *m_AudioIo=nullptr;

    QByteArray m_PCMDataBuffer;
    int m_CurrentPlayIndex=0;

    QMutex m_Mutex;
    bool m_Isplaying=true;

signals:
    void updateplayStatus(void);
};

#endif // JWMUSIC_H
