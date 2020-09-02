#include <QCoreApplication>
#include <QDebug>
#include <QWidget>
#include <QApplication>
#include "mainwindow.h"
#include <QtCharts>
#include <QLabel>
#include "darkpalette.h"
#include <chrono>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    window.profiler.startMeasuring("Style: ");

    qApp->setStyle(QStyleFactory::create("Fusion"));
    darkPalette palette;
    auto darkPollete = palette.setDarkPalette();
    qApp->setPalette(darkPollete);

    window.profiler.finishMeasuring();


    window.profiler.startMeasuring("Show: ");

    window.show();

    window.profiler.finishMeasuring();

    return app.exec();
}
