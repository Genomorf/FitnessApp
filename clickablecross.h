#ifndef CLICKABLECROSS_H
#define CLICKABLECROSS_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class clickableCross : public QLabel
{
    Q_OBJECT
public:
    clickableCross();
    void mousePressEvent(QMouseEvent* event);
signals:
    void clicked(QMouseEvent* e);
};

#endif // CLICKABLECROSS_H
