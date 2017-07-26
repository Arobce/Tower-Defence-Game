#include "SecondTower.h"
#include <QTimer>
#include "bullet.h"
#include "game.h"
#include <QLineF>

extern Game *game;

SecondTower::SecondTower(QGraphicsItem *parent)
{
    //set tower
    setPixmap(QPixmap(":/images/secondtower.png"));

    //connect timer to attack
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(acquire_target()));
    timer->start(1000);

    //attack color
    QPen pen;
    pen.setColor(Qt::darkBlue);
    attack_area->setPen(pen);
}

void SecondTower::fire()
{
    //create bullet
    Bullet *bullet = new Bullet();
    Bullet *bullet1 = new Bullet();
    Bullet *bullet2 = new Bullet();

    //set grapchics
    bullet->setPixmap(QPixmap(":/images/secondtowerbullet.png"));
    bullet1->setPixmap(QPixmap(":/images/secondtowerbullet.png"));
    bullet2->setPixmap(QPixmap(":/images/secondtowerbullet.png"));

    bullet->setPos(x()+50,y()+50);
    bullet1->setPos(x()+50,y()+50);
    bullet2->setPos(x()+50,y()+50);

    QLineF ln(QPoint(x()+50,y()+50),attack_dest);
    int angle = -1*ln.angle();

    bullet->setRotation(angle);
    bullet1->setRotation(angle+10);
    bullet2->setRotation(angle-10);
    scene()->addItem(bullet);
    scene()->addItem(bullet1);
    scene()->addItem(bullet2);
}

void SecondTower::acquire_target()
{
    Tower::acquire_target();
}
