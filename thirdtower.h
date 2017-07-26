#ifndef THIRDTOWER_H
#define THIRDTOWER_H
#include "tower.h"
class ThirdTower:public Tower{
    Q_OBJECT
public:
    ThirdTower(QGraphicsItem *parent=0);
    void fire();
public slots:
    void acquire_target();
};

#endif // THIRDTOWER_H
