#ifndef PROFILER_H
#define PROFILER_H

#include <QString>
#include <chrono>

class Profiler
{
public:
    Profiler();

    void startMeasuring(const QString& string);
    void finishMeasuring();
    void turnOn(bool flag);
private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point finish;

    QString name;
    bool isEnabled = false;

};

#endif // PROFILER_H
