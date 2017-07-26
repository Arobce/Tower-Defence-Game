#include "buildsecondtowericon.h"
#include "game.h"
#include "Secondtower.h"

extern Game *game;

BuildSecondTowerIcon::BuildSecondTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/secondtower.png"));

}

void BuildSecondTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    count = 0;
    if(!game->build){
        game->build =  new SecondTower();
        game->setCursor(QString(":images/secondtower.png"));
        count++;

    }
}

