#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "profiler.h"
#include "Calendar.h"
#include "sqlite.h"
#include <QMainWindow>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QTextBrowser>
#include <QtCharts>
#include <chrono>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void connectToSqlDatabase();

    bool userAddedValue(int* calcValue);
    void addDataToSql(const QString& typeOfTrain, QTextBrowser* textBrowser, int* calcValue);
    void addToCalc(QLineEdit* line, QTextBrowser* textBrowser, int* calcValue);
    void showChart(QChart* chart, QChartView* chartView);
    void cleanTable(QTextBrowser* textBrowser, int& calcValue);

    void mouseMoveEvent(QMouseEvent* e);
    void mousePressEvent(QMouseEvent* e);


    void highlightCurrentDay();
    void createCalendar(const QString& month);
    QFrame* createCalendarDialogFrame();

    Profiler profiler;

private slots:
    void getTextFromFrame(QString str);

    void updateCalendarItem();

    void on_Add_weight_clicked();

    void on_Add_pushups_clicked();

    void on_Add_pullups_clicked();

    void on_Add_squats_clicked();

    void on_show_weight_clicked();

    void on_show_pushups_clicked();

    void on_show_pullups_clicked();

    void on_show_squats_clicked();

    void on_AddPushupsToCalc_clicked();

    void on_AddPullupsToCalc_clicked();

    void on_AddSquatsToCalc_clicked();

    void on_pushButton_showStatics_clicked();

    void on_clear_squats_clicked();

    void on_clear_pullups_clicked();

    void on_clear_pushups_clicked();

    void on_AddDipsToCalc_clicked();

    void on_clean_dips_clicked();

    void on_Add_dips_clicked();

    void on_show_dips_clicked();

    void on_btnHide_clicked();

    void on_btnResize_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_dips_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;

    QString calendarMonth;
    QString frameText = "Rest";

    Calendar calendar;

    SQLite sql;

    std::pair<int,int> rowAndCol;

    QFrame* frame;
    QFrame* calendarMessage;

    bool isResized = false;

    int calcValueDips = 0;
    int calcValueWeight = 0;
    int calcValueSquats = 0;
    int calcValuePullups = 0;
    int calcValuePushups = 0;
    int dx;
    int dy;

    QtCharts::QChart *chart;

    QSize size;
};

#endif // MAINWINDOW_H
