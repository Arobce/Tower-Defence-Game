#include "game.h"
#include <QGraphicsScene>
#include "tower.h"
#include "bullet.h"
#include "enemy.h"
#include "buildFirsttowericon.h"
#include "Firsttower.h"
#include "buildsecondtowericon.h"
#include "buildthirdtowericon.h"
#include "QGraphicsLineItem"
#include "score.h"
#include "header.h"
#include "qdebug.h"
#include <QBrush>
#include <QImage>

Game::Game():QGraphicsView()
{
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);

    //set background
    scene->setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));

    //set scene
    setScene(scene);

    //set cursor
    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);

    //change window
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create a enemy
    spawnTimer = new QTimer(this);
    enemySpawned = 0;
    maxNumberOfEnemies = 0;
    pointsToFollow << QPointF(800,0) << QPointF(450,450) <<
                      QPointF(0,610);
//    pointsToFollow2 << QPointF(300,0) << QPointF(350,350) <<
//                      QPointF(800,610);
    createEnemies(5);
    //create road
    createRoad();

    //test code
    ft = new BuildFirstTowerIcon();
    st = new BuildSecondTowerIcon();
    tt = new BuildThirdTowerIcon();
    st->setPos(x(),y()+100);
    tt->setPos(x(),y()+200);

    scene->addItem(ft);
    scene->addItem(st);
    scene->addItem(tt);



    //score and health
    score = new Score();
    score->setPos(x()+100,y()+15);
    scene->addItem(score);
    health = new Health();
    health->setPos(x()+100,y()+40);
    scene->addItem(health);

}

void Game::setCursor(QString filename)
{
    if(cursor){
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor){
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event)
{
    if(build){
        scene->addItem(build);
        build->setPos(event->pos());
        cursor = nullptr;
        build = nullptr;
        //only allow 1 towers
        if(ft->count==1)
        {
            scene->removeItem(ft);
        }
        if(st->count == 1)
        {
            scene->removeItem(st);
        }
        if(tt->count==1)
        {
            scene->removeItem(tt);
        }
    }
    else{
        QGraphicsView::mousePressEvent(event);
    }
}


void Game::createEnemies(int numberofEnemies)
{
    enemySpawned = 0;
    maxNumberOfEnemies = numberofEnemies;
    connect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnTimer->start(500);

}

void Game::createRoad()
{
    for (size_t i = 0, n = pointsToFollow.size()-1; i < n; i++)
    {
        //create line
        QLineF line(pointsToFollow[i],pointsToFollow[i+1]);
        QGraphicsLineItem *lineItem = new QGraphicsLineItem(line);
        //widht and color
        QPen pen;
        pen.setWidth(5);
        pen.setColor(Qt::darkCyan);
        //set pend and add to scene
        lineItem->setPen(pen);
        scene->addItem(lineItem);

//        //points2
//        QLineF line1(pointsToFollow2[i],pointsToFollow2[i+1]);
//        QGraphicsLineItem *lineItem1 = new QGraphicsLineItem(line1);
//        //widht and color
//        QPen pen1;
//        pen1.setWidth(5);
//        pen1.setColor(Qt::darkGray);
//        //set pend and add to scene
//        lineItem1->setPen(pen1);
//        scene->addItem(lineItem1);
    }
}





void Game::spawnEnemy()
{
    //spwan an enemy
    Enemy *enemy = new Enemy(pointsToFollow);
//    Enemy *enemy1 = new Enemy(pointsToFollow2);
//    enemy1->setPos(pointsToFollow2[0]);
    enemy->setPos(pointsToFollow[0]);
    scene->addItem(enemy);
    //scene->addItem(enemy1);
    enemySpawned+=1;

    if(enemySpawned >= maxNumberOfEnemies){
        spawnTimer->start(500);
    }
}
