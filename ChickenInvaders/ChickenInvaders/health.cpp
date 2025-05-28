#include "health.h"
#include "score.h"
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QFont>
#include <QApplication>

Health::Health( Score *s) : QGraphicsTextItem() {
    score = s;
    health = 3;
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("ariel", 14));
}
void Health::decrease(){
    if(health < 1){
        QMessageBox *Message = new QMessageBox;
        Message->setWindowTitle("Game Over!");
        Message->setText(QString("You Lost. Your score is ")+ QString::number(score->getScoreVal()));
        Message->exec();

        QApplication::quit();
    }
    health--;
    setPlainText("Health: " + QString::number(health));
}
int Health::getHealthVal(){
    return health;
}
