#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Tower:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem *parent=0);
    double distanceTo(QGraphicsItem *item);
    virtual void fire();
    QPointF attack_dest;
    QGraphicsPolygonItem *attack_area;
public slots:
        void acquire_target();
private:


    bool has_target;
};

#endif // TOWER_H
