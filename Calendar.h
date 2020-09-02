#ifndef CALENDAR_H
#define CALENDAR_H
#include <QApplication>

class Calendar
{

//Check git
public:
    Calendar();
    std::map<QString, int> getMonthsMap();

    QString getCurrentMonth();
    QString getNextMonth(const QString& month);
    QString getPreviousMonth(const QString& month);

    int getCurrentDay();

private:
    std::map<QString, int> months = {{"January", 31},
                            {"February", 29},
                            {"March", 31},
                            {"April", 30},
                            {"May", 31},
                            {"June", 30},
                            {"July", 31},
                            {"August", 31},
                            {"September", 30},
                            {"October", 31},
                            {"November", 30},
                            {"December", 31}
                            };

    QList<QString> monthsList {"January",
                            "February",
                            "March",
                            "April",
                            "May",
                            "June",
                            "July",
                            "August",
                            "September",
                            "October",
                            "November",
                            "December"
                           };

};


#endif // CALENDAR_H
