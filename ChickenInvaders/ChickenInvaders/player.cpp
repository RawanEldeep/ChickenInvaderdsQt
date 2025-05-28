#include "player.h"
#include "laser.h"
#include "chickens.h"
#include "health.h"
#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QAudioOutput>


Player::Player(Score *s, Health *h) : QObject(), QGraphicsPixmapItem()
{
    LaserSound = new QMediaPlayer();
    LaserAudio = new QAudioOutput();
    LaserSound->setSource(QUrl("qrc:/resources/audios/lasershot.mp3"));
    LaserSound->setAudioOutput(LaserAudio);
    LaserAudio->setVolume(50);

    score = s;
    health = h;
    setPixmap(QPixmap(":/resources/player/ship.png").scaled(75,75)); //Intialized player object with image, height, and width
}
void Player::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        if(x() > 0){
            setPos(x() - 10, y());
        }
    }
    else if(event->key() == Qt::Key_Right){
        if(x() + 75 < 800){
            setPos(x() + 10, y());
        }

    }
    else if(event->key() == Qt::Key_Space){
        Laser *laser = new Laser(score);
        laser->setPos(x(),y());
        scene()->addItem(laser);
        if(LaserSound->playbackState() == QMediaPlayer::PlayingState){
            LaserSound->setPosition(0);
        }else if(LaserSound->playbackState() == QMediaPlayer::StoppedState){

             LaserSound->play();
        }

    }

}

void Player::Spawn(){
    Chickens *chick = new Chickens(health);
    scene()->addItem(chick);

}
