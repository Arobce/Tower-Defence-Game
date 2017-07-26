#include "buildFirsttowericon.h"
#include "game.h"
#include "Firsttower.h"

extern Game *game;

BuildFirstTowerIcon::BuildFirstTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/tower.png"));

}

void BuildFirstTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    count - 0;
    if(!game->build){
        game->build =  new FirstTower();
        game->setCursor(QString(":images/tower.png"));
    }
    count++;
}

