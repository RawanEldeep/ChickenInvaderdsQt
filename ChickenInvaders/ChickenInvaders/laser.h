#ifndef LASER_H
#define LASER_H

#include "score.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class Laser : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Score *score;
    QMediaPlayer *KillSound;
    QAudioOutput *KillAudio;
public:
    Laser(Score *s);
public slots:
    void Move();
signals:
};

#endif // LASER_H
