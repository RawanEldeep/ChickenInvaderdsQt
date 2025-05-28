#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QTimer>
#include "score.h"
#include "health.h"
#include "player.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Creating the scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QPixmap(":/resources/Background/SceneBG.jpg").scaled(800,600)));

    //Creating the view
    QGraphicsView *view = new QGraphicsView();
    view->setFixedSize(800,600);

    //Disabled scrolling bars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    //creating the score
    Score *score = new Score();
    scene->addItem(score);

    //Creating the health
    Health *health = new Health(score);
    health->setPos(health->x() + 700, health->y());
    scene->addItem(health);
    //Creating the player

    Player *player = new Player(score, health);
    player->setPos(view->width()/2, view->height() - 75);
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();




    //Assigning the scene to the view
    view->setScene(scene);
    view->show();
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(Spawn()));
    timer->start(2000);


    return a.exec();
}
