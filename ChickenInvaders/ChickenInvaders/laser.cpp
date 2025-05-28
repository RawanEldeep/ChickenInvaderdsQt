#include "laser.h"
#include "chickens.h"
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QMediaPlayer>
#include <QAudioOutput>

Laser::Laser(Score *s) : QObject() , QGraphicsPixmapItem()
{
    KillSound = new QMediaPlayer();
    KillAudio = new QAudioOutput();
    KillSound->setSource(QUrl("qrc:/resources/audios/chickenKill.mp3"));
    KillSound->setAudioOutput(KillAudio);
    KillAudio->setVolume(50);

    score = s;
    setPixmap(QPixmap(":/resources/laser/red_laser.png").scaled(20,60));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this , SLOT(Move()));
    timer->start(50);
}
void Laser::Move(){
    QList<QGraphicsItem *> CollidingItems = collidingItems();
    for(int i = 0; i < CollidingItems.size(); i++){
        if(typeid(*(CollidingItems[i])) == typeid(Chickens)){
            score->increase();

            if(KillSound->playbackState() == QMediaPlayer::PlayingState){
                KillSound->setPosition(0);
            }else if(KillSound->playbackState() == QMediaPlayer::StoppedState){

                KillSound->play();
            }

            scene()->removeItem(CollidingItems[i]);
            scene()->removeItem(this);
            delete CollidingItems[i];
            delete this;

        }

    }

    setPos(x(), y() - 10);
    if(y() + 60 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
