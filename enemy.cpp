#include "enemy.h"
#include <QPixmap>
#include <qmath.h>
#include <QTimer>
#include <game.h>
#include <QApplication>
#include <QMessageBox>

extern Game *game;

Enemy::Enemy(QList<QPointF> pointsToFollow,QGraphicsItem *parent)
{
    //set graphics
    setPixmap(QPixmap(":/images/enemy.png"));

    //set points
    points = pointsToFollow;
    point_index = 0;
    dest = points[0];
    rotateToPoint(dest);

    //connect timer to move forward
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}

void Enemy::rotateToPoint(QPointF p)
{
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());

}

void Enemy::move_forward()
{
    //if close to dest, rotate to dest
    QLineF ln(pos(),dest);
    if(ln.length() < 5){
        point_index++;
        if(point_index>=points.size()){
            return;
        }
        dest=points[point_index];
        rotateToPoint(dest);
    }
    //move froward to current
    int STEP_SIZE = 15;
    double theta = rotation(); //degres

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);
    if(pos().y()>600){
        //delete and decrese
        game->health->decrease();
        if(game->health->getHealth() == 0)
        {
            game->close();
            QMessageBox msgBox;
            msgBox.setText("GAME OVER!!");
            msgBox.exec();
            msgBox.setFixedSize(500,500);

        }
        scene()->removeItem(this);
        delete this;
    }
}


