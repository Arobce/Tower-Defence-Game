#include "Firsttower.h"
#include <QTimer>
#include "bullet.h"
#include "game.h"
#include <QLineF>
#include <QPen>

extern Game *game;

FirstTower::FirstTower(QGraphicsItem *parent)
{


   //connect timer to attack
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(acquire_target()));
    timer->start(1000);

    //attack color
    QPen pen;
    pen.setColor(Qt::darkGray);
    attack_area->setPen(pen);

}

void FirstTower::fire()
{
    Bullet *bullet = new Bullet();
    bullet->setPos(x()+50,y()+50);

    QLineF ln(QPoint(x()+50,y()+50),attack_dest);
    int angle = -1*ln.angle();

    bullet->setRotation(angle);
    scene()->addItem(bullet);
}

void FirstTower::acquire_target()
{
    Tower::acquire_target();
}
