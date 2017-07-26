#include "tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "bullet.h"
#include <QPointF>
#include <QLineF>
#include "game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <enemy.h>

extern Game *game;

Tower::Tower(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    //set tower
   setPixmap(QPixmap(":/images/tower.png"));

   //create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
              << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    //scale points
    int SCALE_FACTOR = 75;
    for(size_t i =0,a=points.size();i<a;i++){
        points[i] *= SCALE_FACTOR;
    }


    //polygon item
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->setPen(QPen(Qt::DotLine));

    //move plygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x()+50,y()+50);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());



    //set attack_dest
    attack_dest = QPointF(800,0);
    has_target = false;
}

double Tower::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Tower::fire()
{
    Bullet *bullet = new Bullet();
    bullet->setPos(x()+50,y()+50);

    QLineF ln(QPoint(x()+50,y()+50),attack_dest);
    int angle = -1*ln.angle();

    bullet->setRotation(angle);
    scene()->addItem(bullet);
}

void Tower::acquire_target()
{
    //list all items colliding with attack_area
    QList<QGraphicsItem *> collidin_items = attack_area->collidingItems();

    //assume tower doesnt have target
    has_target = false;

    double closest_dist = 300;
    QPointF closest_pt = QPointF(0,0);
    for(size_t i =0,n=collidin_items.size();i<n;i++)
    {
        Enemy *enemy = dynamic_cast<Enemy *>(collidin_items[i]);
        if(enemy){
            double this_dist = distanceTo(enemy);
            if(this_dist<closest_dist){
                closest_dist = this_dist;
                closest_pt = collidin_items[i]->pos();
                has_target = true;
            }

        }
    }
    // if has target, set the closest enemy as the attack_dest, and fire
    if (has_target){
            attack_dest = closest_pt;
            fire();
        }
}
