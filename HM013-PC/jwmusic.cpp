#include "jwmusic.h"

#include <QPixmap>
#include <QFile>
#include <QPainter>
#include <QFileDialog>
#include <QUrl>
#include <QDebug>
#include <QMediaMetaData>
#include <QMessageBox>
#include <QFileInfo>

jwMusic::jwMusic(QWidget *parent) : QWidget(parent)
{
    QPixmap background;
    background.load(":/image/music_bg.bmp");//加载背景图片
    this -> resize(background.width(),background.height());//设置窗口和背景图片大小一致
    this -> setWindowFlags(Qt::FramelessWindowHint);//产生一个无窗口边框的窗口，用户无法改变它的大小也无法移动它
    add = false;
    moved = 0;
    timer = new QTimer(this);
    timer2 = new QTimer(this);

    player = new QMediaPlayer(this);//QMediaplayer用于解析音频文件和视频文件
    playList = new QMediaPlaylist;

    init_controls();//创建按钮
    init_skin();//外部加载qss文件，绘制界面样式

    connect(player, SIGNAL(metaDataAvailableChanged(bool)), this, SLOT(showMessage(bool)));
    connect(seekSlider,SIGNAL(sliderMoved(int)), this,SLOT(seekChange(int)));
}
//令窗口可以被拖动
void jwMusic::mousePressEvent(QMouseEvent *event){
    if(event->buttons()==Qt::LeftButton)
    {
        dragPosition=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
}

void jwMusic::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        this ->move(event->globalPos() - dragPosition);
        event->accept();
    }
}
//绘制背景
void jwMusic::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    QPixmap backgound;
    backgound.load(":/image/more.png");
    paint.drawPixmap(0, 0, backgound.width(), backgound.height(),backgound);
    event ->accept();

}


//创建按钮
void jwMusic::init_controls()
{
    BtnClose = new QPushButton(this);
    BtnClose -> setObjectName("BtnClose");//如果要对这个对象单独设stylesheet的话一定要设置它的objectName
    BtnClose -> setGeometry(365,2,30,30);//窗口左上角为原点（X365，Y2），（宽30，高30）
    BtnClose -> setToolTip(tr("退出"));
    BtnClose -> setCursor(QCursor(Qt::PointingHandCursor));//鼠标指针形状为手

    BtnMin=new QPushButton(this);
    BtnMin->setObjectName(tr("BtnMin"));
    BtnMin->setGeometry(330,5,25,30);
    BtnMin->setToolTip(tr("最小化"));
    BtnMin->setCursor(QCursor(Qt::PointingHandCursor));

    playPattern=new QPushButton(this);
    /*QIcon icon1(":/image/Seq.png");
    playPattern->setIcon(icon1);*/
    playPattern->setObjectName(tr("playPattern"));
    playPattern->setGeometry(20,255,50,50);
    playPattern->setToolTip(tr("列表循环"));
    playPattern->setCursor(QCursor(Qt::PointingHandCursor));


    BtnPlay=new QPushButton(this);
    BtnPlay->setObjectName(tr("BtnPlay"));
    BtnPlay->setGeometry(160,250,56,56);
    BtnPlay->setToolTip(tr("播放"));
    BtnPlay->setCursor(QCursor(Qt::PointingHandCursor));

    BtnPrev=new QPushButton(this);
    BtnPrev->setObjectName(tr("BtnPrev"));
    BtnPrev->setGeometry(120,255,45,45);
    BtnPrev->setToolTip(tr("上一首"));
    BtnPrev->setCursor(QCursor(Qt::PointingHandCursor));

    BtnNext=new QPushButton(this);
    BtnNext->setObjectName(tr("BtnNext"));
    BtnNext->setGeometry(210,255,45,45);
    BtnNext->setToolTip(tr("下一首"));
    BtnNext->setCursor(QCursor(Qt::PointingHandCursor));

    muteButton=new QPushButton(this);
    muteButton->setObjectName(tr("muteButton"));
    muteButton->setGeometry(370,320,25,25);
    muteButton->setToolTip(tr("关闭声音"));
    muteButton->setCursor(QCursor(Qt::PointingHandCursor));


    volumeControl=new QSlider(Qt::Vertical,this);//QSlider(Qt::Vertical,this)创建一个竖直方向的滑动条QSlider控件
    volumeControl->setObjectName(tr("volumeControl"));
    volumeControl->setGeometry(375,240,15,80);
    volumeControl->setCursor(QCursor(Qt::PointingHandCursor));
    volumeControl->setRange(0,100);//设置滑动条控件的最小值和最大值
    volumeControl ->setValue(50);//设置初值为50；

    seekSlider = new QSlider(Qt::Horizontal,this);//QSlider(Qt::Horizontal,this)创建一个水平方向的滑动条QSlider控件
    seekSlider -> setGeometry(100,345,200,15);
    seekSlider->setObjectName(tr("seekSlider"));
    seekSlider -> setCursor(QCursor(Qt::PointingHandCursor));

    addMore = new QPushButton(this);
    addMore -> setGeometry(295,2,30,30);
    addMore -> setObjectName(tr("addMore"));
    addMore->setToolTip(tr("添加歌曲"));
    addMore -> setCursor(QCursor(Qt::PointingHandCursor));

    showMge = new QLabel(this);
    showMge -> setGeometry(34,320,400,20);
    showMge -> setFont(QFont("Times",10,QFont::Bold));//字体使用Times,10号字体，加粗
    QPalette pac;//创建调色板
    pac.setColor(QPalette::WindowText,QColor(70,80,70));
    showMge -> setPalette(pac);

    list = new QListWidget(this);
    list ->setGeometry(20,50,360,180);
    list -> setFont(QFont("Times",10,QFont::Bold));
    list -> setPalette(pac);
    list ->setStyleSheet("background: rgba(0,0,0,0.1);");


    message = new QLabel(this);
    message -> setGeometry(20,30,140,20);
    message -> setFont(QFont("Times",10,QFont::Bold));
    message -> setPalette(pac);

    showPro = new QLabel(this);
    showPro -> setGeometry(35,340,50,20);
    showPro -> setFont(QFont("Times",10,QFont::Bold));
    showPro -> setPalette(pac);
    QTime mov(0,0,0);
    showPro ->setText(mov.toString("mm:ss"));

    showTime = new QLabel(this);
    showTime -> setGeometry(325,340,50,20);
    showTime -> setFont(QFont("Times",10,QFont::Bold));
    showTime -> setPalette(pac);
    QTime mo(0,0,0);//QTime 提供时间函数给用户使用
    showTime ->setText(mo.toString("mm:ss"));//显示分：秒

    title = new QLabel(this);//设置标题
    title -> setGeometry(5,0,200,30);
    title ->setFont(QFont("Times",15,QFont::Bold));
    QPalette pa;
    pa.setColor(QPalette::WindowText,QColor(0,0,0));
    title -> setPalette(pa);
    title -> setText("MusicPlayer");



    //信号与槽
    connect(BtnClose, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(BtnMin, SIGNAL(clicked(bool)), this, SLOT(showMinimized()));
    connect(addMore, SIGNAL(clicked(bool)), this, SLOT(addMoremusic()));
    connect(BtnPlay, SIGNAL(clicked(bool)), this, SLOT(playMusic()));
    connect (BtnPrev,SIGNAL(clicked(bool)), this, SLOT(preMusic()));
    connect(BtnNext, SIGNAL(clicked(bool)), this, SLOT(nextMusic()));
    connect(muteButton, SIGNAL(clicked(bool)), this, SLOT(meteOpen()));
    connect(volumeControl, SIGNAL(sliderMoved(int)), this, SLOT(volumChange(int)));
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT( positionChange(qint64)));
    connect(playPattern,SIGNAL(clicked(bool)),this,SLOT(musicPlayPattern()));

}
//外部加载qss文件，绘制界面样式
void jwMusic::init_skin()
{
    QFile file(":/qss/skin.qss");
    file.open(QFile::ReadOnly);
    this -> setStyleSheet(QObject::tr(file.readAll()));
    file.close();

}
