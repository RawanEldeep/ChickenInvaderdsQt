#include "chickens.h"
#include "health.h"
#include <QPixMap>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>


Chickens::Chickens(Health *h) : QObject() , QGraphicsPixmapItem(){
    health = h;
   int randomPos = rand() % 700;
    setPos(randomPos, 0);

    setPixmap(QPixmap(":/resources/PinkChick/PinkcChick .png").scaled(100, 100));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(Move()));
    timer->start(50);

}
void Chickens::Move(){
    setPos(x(), y() + 5);
    if(y() > 600){
        health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
