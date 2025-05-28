#ifndef PLAYER_H
#define PLAYER_H

#include "score.h"
#include "health.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class Player : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Score *score;
    Health *health;
    QMediaPlayer *LaserSound;
    QAudioOutput *LaserAudio;
public:
    Player(Score *s = 0, Health *h = 0); //Created Constructor
    void keyPressEvent(QKeyEvent *event);
public slots:
    void Spawn();
signals:
};

#endif // PLAYER_H
