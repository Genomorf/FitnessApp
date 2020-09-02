#ifndef SQLITE_H
#define SQLITE_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

class SQLite
{
public:
    SQLite();

    QSqlDatabase db;

    bool updateSqlCalendar(const QString& month,  QString text,
                           const int row, const int col);
    void connectToSql();

    QString insertDataToSql(const QString& typeOfTraining, const int& value);

    QList<int> getWeightFromSql();

    QSqlQuery readCalendarFromSql(const QString& month);
    QSqlQuery showSqlData(const QString& typeOfTraining);
};

#endif // SQLITE_H
