#ifndef SECONDTOWER_H
#define SECONDTOWER_H
#include "tower.h"

class SecondTower:public Tower{
    Q_OBJECT
public:
    SecondTower(QGraphicsItem *parent=0);
    void fire();
public slots:
    void acquire_target();
};

#endif // SECONDTOWER_H
