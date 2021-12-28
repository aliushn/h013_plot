#include "jwmusic.h"

jwMusic::jwMusic(QObject *parent):QThread(parent)
{
    m_PCMDataBuffer.clear();
}

jwMusic::~jwMusic()
{

}

jwMusic* jwMusic::getInstance(void)
{
    static jwMusic instance;
    return &instance;
}

void jwMusic::setCurrentBuffer(QByteArray buffer)
{
    QMutexLocker locker(&m_Mutex);

    m_PCMDataBuffer.clear();
    m_PCMDataBuffer=buffer;
    m_Isplaying=true;
}

void jwMusic::setCurrentSampleInfo(int sampleRate, int sampleSize, int channelCount)
{
    QMutexLocker locker(&m_Mutex);

    QAudioFormat nFormat;
    nFormat.setSampleRate(sampleRate);
    nFormat.setSampleSize(sampleSize);
    nFormat.setChannelCount(channelCount);
    nFormat.setCodec("audio/pcm");
    nFormat.setByteOrder(QAudioFormat::LittleEndian);
    nFormat.setSampleType(QAudioFormat::UnSignedInt);

    if(m_OutPut!=nullptr)
        delete m_OutPut;
    m_OutPut=new QAudioOutput(nFormat);
    m_AudioIo=m_OutPut->start();
}

void jwMusic::run(void)
{
 while(!this->isInterruptionRequested())
 {
     if(!m_Isplaying)
     {
         continue;
         QThread::msleep(10);
     }

     QMutexLocker locker(&m_Mutex);
     if((m_PCMDataBuffer.count()<=0)||(m_CurrentPlayIndex>=m_PCMDataBuffer.count())){
         QThread::msleep(10);
         continue;
     }

     if(m_OutPut->bytesFree()>=m_OutPut->periodSize())
     {
        char *writeData=new char [ m_OutPut->periodSize()];
        //获取要播放的数据
        int size=m_OutPut->periodSize();
        size=qMin(size,m_PCMDataBuffer.size()-m_CurrentPlayIndex);
        memcpy(writeData,&m_PCMDataBuffer.data()[m_CurrentPlayIndex],size);
        //写入音频数据
        m_AudioIo->write(writeData,size);
        m_CurrentPlayIndex+=size;

        emit updateplayStatus();
        delete []writeData;
        QThread:msleep(10);
     }
 }
}



// 添加数据

void jwMusic::addAudioBuffer(const char* pData, int len)
{
    QMutexLocker locker(&m_Mutex);

    m_PCMDataBuffer.append(pData, len);
    m_Isplaying = true;
}

void jwMusic::cleanAudioBuffer(void)
{
    QMutexLocker locker(&m_Mutex);
    m_CurrentPlayIndex = 0;
    m_PCMDataBuffer.clear();
    m_Isplaying = false;
}

void jwMusic::playMusic(bool status)
{
    m_Isplaying = status;
}

bool jwMusic::getPlayMusicStatus(void)
{
    return m_Isplaying;
}

void jwMusic::setCurrentVol(qreal volumn)
{
    if (m_OutPut)
        m_OutPut->setVolume(volumn);
}

qreal jwMusic::getCurrentVol(void)
{
    if (!m_OutPut)
        return 0;

    return m_OutPut->volume();
}

// 获取当前的所在位置大小
int jwMusic::getCurrentBufferIndex(void)
{
    return m_CurrentPlayIndex;
}

int jwMusic::getCurrentTime(void)
{
    QMutexLocker locker(&m_Mutex);

    qreal sec = m_CurrentPlayIndex * 1.0 / 4 * (1 * 1.0 / m_OutPut->format().sampleRate());
    return sec * 1000;
}



















