#ifndef JWMUSIC_H
#define JWMUSIC_H

#include <QObject>
#include <QWidget>
/////////////////////////////////////////
#include <QWidget>
#include <QMediaPlayer>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QTime>
#include <QPaintEvent>
#include <QMediaPlaylist>
#include <QTimer>
#include <QListWidget>

class jwMusic:public QWidget
{
    Q_OBJECT
public:
    explicit  jwMusic(QWidget *parent);

     public slots:
         void addMoremusic();
        void playMusic();
        void preMusic();
        void nextMusic();
        void meteOpen();
        void volumChange(int);
        void positionChange(qint64 position);
        void showMessage(bool);
        void seekChange(int position);
        void posChange();
        void clearMessage();
        void musicPlayPattern();

    private:
        void init_controls();
        void init_skin();

        QPushButton *BtnClose;
           QPushButton *BtnMin;
           QPushButton *BtnPlay;
           QPushButton *BtnPrev;
           QPushButton *BtnNext;
           QPushButton *muteButton;
           QPushButton *addMore;
           QPushButton *playPattern;
           QSlider     *volumeControl;
           QSlider     *seekSlider;
           QLabel      *showTime;
           QLabel      *showPro;
           QLabel      *showMge;
           QLabel      *title;
           QLabel      *message;
           QListWidget *list;
           bool        add;
           QTimer      *timer;
           QTimer      *timer2;
           int         moved;
           QPoint      dragPosition;
           QMediaPlayer   *player;
           QMediaPlaylist * playList;

        protected:
        void paintEvent(QPaintEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
};

#endif // JWMUSIC_H
