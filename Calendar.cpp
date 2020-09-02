#include "Calendar.h"
#include <windows.h>
#include <QDebug>
#include <QList>
#include <algorithm>

Calendar::Calendar()
{
}

std::map<QString, int> Calendar::getMonthsMap()
{
    return this->months;
}

QString Calendar::getCurrentMonth()
{
    SYSTEMTIME systemtime;
    GetSystemTime(&systemtime);

    return monthsList[systemtime.wMonth - 1];
    throw  "Failed to find a month";
}

int Calendar::getCurrentDay()
{
    SYSTEMTIME systemtime;
    GetSystemTime(&systemtime);

    return systemtime.wDay;
    throw  "Failed to find a day";
}

QString Calendar::getNextMonth(const QString& month)
{
    auto it = std::find(monthsList.begin(), monthsList.end(), month);
    if (it == monthsList.end() - 1){
        it = monthsList.begin();
        return *it;
    }
    return *++it;
}

QString Calendar::getPreviousMonth(const QString& month)
{
    auto it = std::find(monthsList.rbegin(), monthsList.rend(), month);
    if (it == monthsList.rend() - 1){
        it = monthsList.rbegin();
        return *it;
    }
    return *++it;
}
