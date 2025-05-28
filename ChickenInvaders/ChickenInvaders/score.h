#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QObject>

class Score :  public QGraphicsTextItem
{
public:
    Score();
    void increase();
    int getScoreVal();
private:
    int scoreVal;
};

#endif // SCORE_H
