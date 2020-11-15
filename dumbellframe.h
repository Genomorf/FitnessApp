#ifndef DUMBELLFRAME_H
#define DUMBELLFRAME_H
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include "clickablecross.h"
class dumbellFrame : public QObject
{
public:
    dumbellFrame();
    void imageClicked();
    QFrame* createDumbellFrame();
    void changeSetsLabel(QString);
    void changeWeightLabel(QString);
    bool checkIfLetter(QString string);
    QFrame* createDumbellFrameEmpty();
    QLineEdit* trainingNameLabel;
    QLineEdit* weightCounterLabel;
    QLineEdit* setsCounterLabel;
    void changeLabel(QString string, QString& counter, QLineEdit* label);
    void incrWeight();
    void decrWeight();
    void incrSets();
    void decrSets();
    QString changeNum(QString, bool);
    std::pair<int, int> counterButtonsSize{25, 15};
    std::pair<int, int> labelSize{90, 30};
    QLabel* dumbellImage;
    QFrame* frame;
    QString weight = "0";
    QString sets = "0";
    QFont textFont;
    clickableCross *crossImage;
};

#endif // DUMBELLFRAME_H
