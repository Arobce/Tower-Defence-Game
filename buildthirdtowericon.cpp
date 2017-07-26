#include "buildThirdTowericon.h"
#include "game.h"
#include "ThirdTower.h"

extern Game *game;

BuildThirdTowerIcon::BuildThirdTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/thirdtower.png"));

}

void BuildThirdTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    count = 0;
    if(!game->build){
        game->build =  new ThirdTower();
        game->setCursor(QString(":images/thirdtower.png"));
        count++;
    }
}

