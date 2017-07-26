#include <bullet.h>
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <game.h>
#include <QList>
#include "enemy.h"
#include <typeinfo.h>

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent)
{
    //set graphics
    setPixmap(QPixmap(":/images/arrow.png"));

    //timer to move()
    QTimer *move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);

    //initialize values
    maxRange = 100;
    distanceTravelled = 0;

}



void Bullet::move()
{
    //if bullets collide, destroy the enemey
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0,n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Enemy)){
            //increase score
            game->score->increase();
            //remove both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete both
            delete colliding_items[i];
            delete this;
            return;

        }
    }

    int STEP_SIZE = 3;
    double theta = rotation(); //degres

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);
}

