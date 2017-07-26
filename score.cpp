#include <score.h>
#include <QFont>


Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //initialize score to zero
    score = 0;

    //text
    setPlainText(QString("Score: ")+ QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));



}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+ QString::number(score));
}

int Score::getScore()
{
    return score;
}


