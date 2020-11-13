#ifndef DUMBELLFRAME_H
#define DUMBELLFRAME_H
#include <QFrame>
#include <QLabel>
#include <QLineEdit>

class dumbellFrame : public QObject
{
public:
    dumbellFrame();
    QFrame* create();
    void changeDesc(QString);
    void changeWeight(QString);
    QLineEdit* trainingNameLabel;
    QLineEdit* weightCounterLabel;
    QLineEdit* setsCounterLabel;
    void incrWeight();
    void decrWeight();
    std::pair<int, int> counterButtonsSize{25, 15};
    std::pair<int, int> labelSize{90, 30};

    QString weight = "0";
};

#endif // DUMBELLFRAME_H
