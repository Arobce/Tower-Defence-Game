#ifndef BROWNTOWER_H
#define BROWNTOWER_H
#include "tower.h"

class FirstTower:public Tower{
    Q_OBJECT
public:
    FirstTower(QGraphicsItem *parent=0);
    void fire();
public slots:
    void acquire_target();
};

#endif // BROWNTOWER_H
