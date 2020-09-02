#ifndef CHART_H
#define CHART_H

#include <QtCharts>
#include "sqlite.h"

QChart* createChart(SQLite& sql, const QString& typeOfTrain);

#endif // CHART_H
