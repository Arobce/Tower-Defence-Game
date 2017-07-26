#ifndef BUILDTOWERICON_H
#define BUILDTOWERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
class BuildFirstTowerIcon: public QGraphicsPixmapItem{
public:
    BuildFirstTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //propety
    int count;
};

#endif // BUILDTOWERICON_H
