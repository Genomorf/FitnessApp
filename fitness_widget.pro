QT += core gui sql widgets charts

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        calendar.cpp \
        chart.cpp \
        clickablecross.cpp \
        darkpalette.cpp \
        dumbellframe.cpp \
        main.cpp \
        mainwindow.cpp \
        profiler.cpp \
        sqlite.cpp \
        statistics.cpp \
        unittests.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    mainwindow.ui

HEADERS += \
    calendar.h \
    chart.h \
    clickablecross.h \
    darkpalette.h \
    dumbellframe.h \
    mainwindow.h \
    profiler.h \
    sqlite.h \
    statistics.h \
    unittests.h

RC_FILE = icon.rc

