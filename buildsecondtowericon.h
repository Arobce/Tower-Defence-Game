#ifndef BUIDSECONDTOWERICON_H
#define BUIDSECONDTOWERICON_H


#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
class BuildSecondTowerIcon: public QGraphicsPixmapItem{
public:
    BuildSecondTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    int count;
};

#endif // BUIDSECONDTOWERICON_H
