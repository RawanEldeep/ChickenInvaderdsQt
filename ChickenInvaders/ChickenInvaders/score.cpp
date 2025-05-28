#include "score.h"
#include <QGraphicsTextItem>
#include <QFont>

Score::Score() : QGraphicsTextItem() {
    scoreVal = 0;
    setPlainText("Score: " + QString::number(scoreVal));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("ariel", 14));
}
void Score::increase(){
    scoreVal++;
    setPlainText("Score: " + QString::number(scoreVal));
}
int Score::getScoreVal(){
    return scoreVal;
}
