#include <QApplication>
#include <cmath>
#include <QDebug>
#include "profiler.h"


int meanStat(QList<int> list)
{
    auto profiler = Profiler();
    profiler.startMeasuring("Mean: ");

    int sum = std::accumulate(list.begin() , list.end(), 0);
    int mean = sum / list.count();
    qDebug() << QString("Mean: %1").arg(mean);

    profiler.finishMeasuring();
    return mean; 
}

int standartDeviation(QList<int> list, int mean)
{
    auto profiler = Profiler();
    profiler.startMeasuring("SD: ");

    QList<int> tempList = QList<int>();
    for (int i : list){
        tempList.append((i - mean) * (i - mean));
    }
    int SD = sqrt(std::accumulate(tempList.begin(), tempList.end(), 0))
            / tempList.count() - 1;
    qDebug() << QString("SD: %1 ").arg(SD);

    profiler.finishMeasuring();
    return SD;
}

int dynamicStat(QList<int> list)
{
    auto profiler = Profiler();
    profiler.startMeasuring("Dynamic: ");

    int sum = std::accumulate(list.begin(), list.end() - 1, 0);
    int dynamic = list.last() - (sum / (list.count() - 1));
    qDebug() << QString("Dynamic: %1").arg(dynamic);

    profiler.finishMeasuring();
    return dynamic;
}
