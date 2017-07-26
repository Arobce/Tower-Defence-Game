#include <Health.h>
#include <QFont>


Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //initialize Health to 10
    health = 10;

    //text
    setPlainText(QString("Health: ")+ QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));



}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ")+ QString::number(health));
}

int Health::getHealth()
{
    return health;
}


