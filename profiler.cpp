#include "profiler.h"
#include <QDebug>


Profiler::Profiler(){};

void Profiler::turnOn(bool flag)
{
    isEnabled = flag;
}

void Profiler::startMeasuring(const QString& string)
{
    start = std::chrono::steady_clock::now();
    name = string;
}

void Profiler::finishMeasuring()
{
    finish = std::chrono::steady_clock::now();
    auto d = finish - start;
    if (isEnabled){
        qDebug() << name
                 << std::chrono::duration_cast<std::chrono::milliseconds>(d).count()
                 << "ms.\n";
    }
}
