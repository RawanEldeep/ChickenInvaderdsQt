#ifndef HEALTH_H
#define HEALTH_H
#include "score.h"
#include <QGraphicsTextItem>
class Health : public QGraphicsTextItem
{
public:
    Health(Score *score);
    void decrease();
    int getHealthVal();
private:
    int health;
    Score *score;
};

#endif // HEALTH_H
