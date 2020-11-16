#include "clickablecross.h"
#include <QDebug>

clickableCross::clickableCross()
{

}

void clickableCross::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "Clicked!";
    emit clicked(event);
}
