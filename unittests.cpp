#include "unittests.h"
#include "statistics.h"
#include <QDebug>

unitTests::unitTests()
{

}

void unitTests::RunTests(){
    meanStatTest();
    SDTest();
    dynamicStatTest();
    qDebug() << "\n";
}

void unitTests::meanStatTest(){

    QList<int> v1{10,20,30,40};
    QList<int> v2{10};
    QList<int> v3{0};
    Q_ASSERT(meanStat(v1) == 25);
    Q_ASSERT(meanStat(v2) == 10);
    Q_ASSERT(meanStat(v3) == 0);
    qDebug() << "meanStatTest: PASSED";
}

void unitTests::SDTest(){
    QList<int> v1{10,20,30,40};
    QList<int> v2{10};
    QList<int> v3{0};
    Q_ASSERT(standartDeviation(v1, meanStat(v1)) == 4);
    Q_ASSERT(standartDeviation(v2, meanStat(v1)) == 0);
    Q_ASSERT(standartDeviation(v3, meanStat(v1)) == 0);

    qDebug() << "SDTest: PASSED";
}

void unitTests::dynamicStatTest(){
    QList<int> v1{10,20,30,40};
    QList<int> v2{10};
    QList<int> v3{0};
    Q_ASSERT(dynamicStat(v1) == 20);
    Q_ASSERT(dynamicStat(v2) == 0);
    Q_ASSERT(dynamicStat(v3) == 0);

    qDebug() << "dynamicTest: PASSED";
}
