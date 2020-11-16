#include "dumbellframe.h"
#include <QWidget>
#include <QGuiApplication>
#include <QFrame>
#include <QLabel>
#include <QDebug>
#include <QLayout>
#include <QImageReader>
#include <QToolBar>
#include <QAction>
#include <QPushButton>
#include <QSpacerItem>
#include <QtCore>
#include <QMessageBox>
#include "clickablecross.h"

dumbellFrame::dumbellFrame()
{
    frame = new QFrame();
    frame->setMaximumWidth(250);
    frame->setMaximumHeight(250);
    frame->setStyleSheet("background-color: rgb(50, 50, 50);");

    QFont textFont;
    textFont.setPixelSize(15);
    textFont.setBold(true);

    QImageReader reader("dumbell.png");
    qDebug() << reader.imageFormat();
    reader.setAutoTransform(true);
    QImage newImage = reader.read();
    dumbellImage = new QLabel();
    dumbellImage->setAlignment(Qt::AlignCenter);
    dumbellImage->setPixmap(QPixmap::fromImage(newImage.scaled(150,120)));

    textFont.setPixelSize(15);
    textFont.setBold(true);
}

QFrame* dumbellFrame::createDumbellFrameEmpty(){
    QImageReader reader("cross.png");
    qDebug() << reader.imageFormat();
    reader.setAutoTransform(true);
    QImage newImage = reader.read();
    crossImage = new clickableCross();
    crossImage->setAlignment(Qt::AlignCenter);
    crossImage->setPixmap(QPixmap::fromImage(newImage.scaled(80,80)));
//    crossImage->setStyleSheet("color:rgba(255, 255, 255, 0);") ;
//    crossImage->fill
//    connect(crossImage, &clickableCross::clicked, this, &dumbellFrame::imageClicked);
    QVBoxLayout *la = new QVBoxLayout();
    la->addWidget(dumbellImage);
    la->addWidget(crossImage);

    la->setAlignment(Qt::AlignCenter);
    frame->setLayout(la);

    QVBoxLayout *la2 = new QVBoxLayout();
    la2->addWidget(frame);

    return frame;
}


QFrame* dumbellFrame::createDumbellFrame(){

//    QFrame* frame = new QFrame();
//    frame->setMaximumWidth(250);
//    frame->setMaximumHeight(250);
//    frame->setStyleSheet("background-color: rgb(50, 50, 50);");

//    QFont textFont;
//    textFont.setPixelSize(15);
//    textFont.setBold(true);

//    QImageReader reader("dumbell.png");
//    qDebug() << reader.imageFormat();
//    reader.setAutoTransform(true);
//    QImage newImage = reader.read();
//    QLabel* dumbellImage = new QLabel();
//    dumbellImage->setAlignment(Qt::AlignCenter);
//    dumbellImage->setPixmap(QPixmap::fromImage(newImage.scaled(150,120)));

    trainingNameLabel = new QLineEdit();
    trainingNameLabel->setText("Second");
    trainingNameLabel->setAlignment(Qt::AlignCenter);
    trainingNameLabel->setMinimumHeight(labelSize.second);

    weightCounterLabel = new QLineEdit();
    weightCounterLabel->setText(weight);
    weightCounterLabel->setAlignment(Qt::AlignCenter);
    weightCounterLabel->setMaximumSize(labelSize.first, labelSize.second);
    connect(weightCounterLabel, &QLineEdit::textChanged, this, &dumbellFrame::changeWeightLabel);

    setsCounterLabel = new QLineEdit();
    setsCounterLabel->setText(sets);
    setsCounterLabel->setAlignment(Qt::AlignCenter);
    setsCounterLabel->setMaximumSize(labelSize.first, labelSize.second);
    connect(setsCounterLabel, &QLineEdit::textChanged, this, &dumbellFrame::changeSetsLabel);

    QPushButton* weightIncr = new QPushButton();
    weightIncr->setMaximumSize(counterButtonsSize.first, counterButtonsSize.second);
    weightIncr->setText("+");
    connect(weightIncr, &QPushButton::clicked, this, &dumbellFrame::incrWeight);

    QPushButton* weightDecr = new QPushButton();
    weightDecr->setMaximumSize(counterButtonsSize.first, counterButtonsSize.second);
    weightDecr->setText("-");
    connect(weightDecr, &QPushButton::clicked, this, &dumbellFrame::decrWeight);

    QPushButton* setsIncr = new QPushButton();
    setsIncr->setMaximumSize(counterButtonsSize.first, counterButtonsSize.second);
    setsIncr->setText("+");
    connect(setsIncr, &QPushButton::clicked, this, &dumbellFrame::incrSets);

    QPushButton* setsDecr = new QPushButton();
    setsDecr->setMaximumSize(counterButtonsSize.first, counterButtonsSize.second);
    setsDecr->setText("-");
    connect(setsDecr, &QPushButton::clicked, this, &dumbellFrame::decrSets);

    QVBoxLayout* weightButtonsLayout = new QVBoxLayout();
    weightButtonsLayout->setAlignment(Qt::AlignLeft);
    weightButtonsLayout->addWidget(weightIncr);
    weightButtonsLayout->setSpacing(0);
    weightButtonsLayout->addWidget(weightDecr);

    QVBoxLayout* setsButtonsLayout = new QVBoxLayout();
    setsButtonsLayout->addWidget(setsIncr);
    setsButtonsLayout->setSpacing(0);
    setsButtonsLayout->addWidget(setsDecr);

    QHBoxLayout* weightAndSetsLayout = new QHBoxLayout();
    weightAndSetsLayout->addWidget(weightCounterLabel);
    weightAndSetsLayout->addLayout(weightButtonsLayout);
    weightAndSetsLayout->addWidget(setsCounterLabel);
    weightAndSetsLayout->addLayout(setsButtonsLayout);

    trainingNameLabel->setFont(textFont);
    weightCounterLabel->setFont(textFont);
    setsCounterLabel->setFont(textFont);

    QPushButton* b1 = new QPushButton();
    b1->setMaximumSize(50,50);
    b1->setText("SAVE");
    b1->setStyleSheet("background-color: rgb(4, 80, 0);");
    QPushButton* b2 = new QPushButton();
    b2->setMaximumSize(50,50);
    b2->setText("DEL");
    b2->setStyleSheet("background-color: rgb(130, 4, 0);");
    QHBoxLayout* b = new QHBoxLayout();
    //b->setAlignment(Qt::AlignRight);
    b->addWidget(b1);
    b->addSpacing(122);
    b->addWidget(b2);
//    QToolBar *b = new QToolBar();
//    QAction* a = new QAction("b",0);
//    QAction* a2 = new QAction("c",0);
//    a2->setText("3");
//    a->setText("2");
//    b->addAction(a);
//    b->addAction(a2);

    QVBoxLayout *la = new QVBoxLayout();
    la->addWidget(dumbellImage);
    la->addWidget(trainingNameLabel);
    la->addLayout(weightAndSetsLayout);
    la->addLayout(b);

    la->setAlignment(Qt::AlignCenter);
    frame->setLayout(la);

    QVBoxLayout *la2 = new QVBoxLayout();
    la2->addWidget(frame);

    return frame;
}

QString dumbellFrame::changeNum(QString num, bool incr){
    int tmp = num.toInt();
    if (incr)
        ++tmp;
    else
        --tmp;
    qDebug() << tmp << ' ' << weight << ' ' << sets << '\n';
    return QString::number(tmp);
}

void dumbellFrame::incrWeight(){
    weight = changeNum(weight, true);
    weightCounterLabel->setText(weight);
}

void dumbellFrame::decrWeight(){
    weight = changeNum(weight, false);
    weightCounterLabel->setText(weight);
}

void dumbellFrame::incrSets(){
    sets = changeNum(sets, true);
    setsCounterLabel->setText(sets);
}

void dumbellFrame::decrSets(){
    sets = changeNum(sets, false);
    setsCounterLabel->setText(sets);
}

bool dumbellFrame::checkIfLetter(QString string){
    QRegExp re("\\d*");
    if (!re.exactMatch(string)){
       QMessageBox::warning(nullptr, "Error", "You must type only integer values");
       qDebug() << "Not integers where added!";
       return true;
    }
    return false;
}

void dumbellFrame::changeLabel(QString string, QString& counter, QLineEdit* label){
    if (checkIfLetter(string)){
            label->setText(counter);
            return;
    }
    counter = string;
    label->setText(string);
}

void dumbellFrame::changeSetsLabel(QString string){
    changeLabel(string, sets, setsCounterLabel);
}

void dumbellFrame::changeWeightLabel(QString string){
    changeLabel(string, weight, weightCounterLabel);
}

