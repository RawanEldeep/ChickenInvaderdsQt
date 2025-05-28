#ifndef CHICKENS_H
#define CHICKENS_H

#include "health.h"
#include <QGraphicsPixmapItem>
#include <QObject>

class Chickens : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Health *health;
public:
    Chickens(Health *h);
public slots:
    void Move();
signals:
};

#endif // CHICKENS_H
