#include "ThirdTower.h"
#include <QTimer>
#include "bullet.h"
#include "game.h"
#include <QLineF>

extern Game *game;

ThirdTower::ThirdTower(QGraphicsItem *parent)
{
    //set tower
    setPixmap(QPixmap(":/images/thirdtower.png"));

    //connect timer to attack
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(acquire_target()));
    timer->start(1000);

    //attack color
    QPen pen;
    pen.setColor(Qt::red);
    attack_area->setPen(pen);
}

void ThirdTower::fire()
{
    Bullet *bullet = new Bullet();

    //set graphics
    bullet->setPixmap(QPixmap(":/images/thirdtowerbullet.png"));
    bullet->setPos(x()+50,y()+50);

    QLineF ln(QPoint(x()+50,y()+50),attack_dest);
    int angle = -1*ln.angle();

    bullet->setRotation(angle);
    scene()->addItem(bullet);
}

void ThirdTower::acquire_target()
{
    Tower::acquire_target();
}
