#include "sqlite.h"
#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

SQLite::SQLite()
{
}

void SQLite::connectToSql()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    QString db_release("fitness.db");
    QString db_debug("C:\\Users\\Alex\\Documents\\build-fitness_widget-Desktop_Qt_5_15_0_MinGW_32_bit-Debug\\debug\\fitness.db");
    db.setDatabaseName(db_debug);

    if(db.open()){
        qDebug() << "DB open";
    } else {
        qDebug() << "Couldn't open db";
    }
}

QSqlQuery SQLite::showSqlData(const QString& typeOfTraining)
{
    QSqlQuery query = QSqlQuery(db);
    auto queryStr = QString("SELECT * FROM %1").arg(typeOfTraining);

    if (query.exec(queryStr))
        qDebug() << QString("Successfull: %1").arg(queryStr);
    else
        qDebug() << QString("Failed: %1").arg(queryStr);

    return query;
}


QString SQLite::insertDataToSql(const QString& typeOfTraining, const int& value)
{
    QSqlQuery query = QSqlQuery(db);
    auto queryLastValue = QString("SELECT * FROM %1 ORDER BY Id DESC LIMIT 1").arg(typeOfTraining);

    if (query.exec(queryLastValue)){
        qDebug() << "Got last value: ";
    } else {
        qDebug() << "Couldn't get last value";
    }

    query.first();
    auto lastValue = query.value(0).toInt();
    qDebug() << lastValue;

    auto queryInsertValue = QString("INSERT INTO %3 (Id, value) VALUES (%1, %2)").
            arg(lastValue + 1).arg(value).arg(typeOfTraining);
    qDebug() << queryInsertValue;

    if (query.exec(queryInsertValue)){
        qDebug() << "Insert success";
        return QString("Insert success: %1 to a %2 table!").arg(value).arg(typeOfTraining);
    }
    else {
        qDebug() << "Insert failed";
        return QString("Insert failed: wrong data");
    }
}

QList<int> SQLite::getWeightFromSql()
{
    QList<int> table = QList<int>();
    QSqlQuery query = QSqlQuery(db);

    if (query.exec("SELECT * FROM weight")){
        qDebug() << "getWeight success";
    } else {
        qDebug() << "getWeight failed";
    }

    while(query.next()){
        int value = query.value(1).toInt();
        table.append(value);
    }
    return table;
}

bool SQLite::updateSqlCalendar(const QString& month, QString text,
                               const int row, const int col)
{
    QSqlQuery query = QSqlQuery(db);
    QString queryTxt = QString("DELETE FROM %1 WHERE row=%2 AND col=%3")
            .arg(month).arg(row).arg(col);

    if(query.exec(queryTxt)){
        qDebug() << "Delete success!";
    } else {
        qDebug() << "Delete failed!";
    }

    query.finish();
    queryTxt = QString("INSERT INTO %1 (type, row, col) VALUES ('%2', %3, %4);")
            .arg(month).arg(text).arg(row).arg(col);

    if(query.exec(queryTxt)){
        qDebug() << "Insert to a months table success!";
        return true;
    } else {
        qDebug() << "Insert to a months table failed!";
        return false;
    }
}

QSqlQuery SQLite::readCalendarFromSql(const QString& month)
{
    QSqlQuery query = QSqlQuery(db);
    QString queryTxt = QString("SELECT * FROM %1").arg(month);

    if(query.exec(queryTxt)){
        qDebug() << "Select from months table success!";
    } else {
        qDebug() << "Select from months table failed!";
    }
   // qDebug() << query.next();
    return query;
}
