#-------------------------------------------------
#
# Project created by QtCreator 2014-09-08T18:35:39
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tempore
TEMPLATE = app


SOURCES += \
    src/main.cpp \
    src/ui/mainwindow.cpp \
    src/ui/dashboardwidget.cpp \
    src/ui/calenderwidget.cpp \
    src/ui/projectswidget.cpp \
    src/db/dbmgr.cpp \
    src/ui/projectdialog.cpp
HEADERS  += \
    src/ui/mainwindow.h \
    src/ui/dashboardwidget.h \
    src/ui/calenderwidget.h \
    src/ui/projectswidget.h \
    src/db/dbmgr.h \
    src/ui/projectdialog.h

FORMS    += \
    src/ui/mainwindow.ui \
    src/ui/dashboardwidget.ui \
    src/ui/calenderwidget.ui \
    src/ui/projectswidget.ui \
    src/ui/projectdialog.ui
