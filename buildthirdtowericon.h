#ifndef BUILDTHIRDTOWERICON_H
#define BUILDTHIRDTOWERICON_H


#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
class BuildThirdTowerIcon: public QGraphicsPixmapItem{
public:
    BuildThirdTowerIcon(QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    int count;
};

#endif // BUILDTHIRDTOWERICON_H
