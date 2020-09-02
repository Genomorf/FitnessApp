#include <QtCharts>
#include "chart.h"
#include "sqlite.h"
#include <QSqlDatabase>
#include <QSqlQuery>


QChart* createChart(SQLite& sql, const QString& typeOfTrain)
{
    auto query = sql.showSqlData(typeOfTrain);
    QLineSeries* series = new QLineSeries();
    QChart* chart = new QChart();

    while(query.next()){
        int Id = query.value(0).toInt();
        int value = query.value(1).toInt();
        //qDebug() << Id << value;
        series->append(Id, value);
    }
    series->setPointsVisible();

    chart->legend()->hide();
    chart->addSeries(series);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Kg");
    axisY->setRange(0, 100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis;
    axisX->setLabelFormat("%i");
    axisX->setTitleText("Days");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    chart->setTheme(QChart::ChartThemeDark);
    chart->setTitle(typeOfTrain.toUpper());
    chart->setAnimationOptions(QChart::AllAnimations);
    return chart;
}
