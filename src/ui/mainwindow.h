#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../db/dbmgr.h"
#include "dashboardwidget.h"
#include "projectswidget.h"
#include "calenderwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void menu_change_to_dashboard();
    void menu_change_to_projects();
    void menu_change_to_calender();
    void view_changed(int index);

private:
    Ui::MainWindow *ui;
    DashboardWidget* dashWiget_;
    ProjectsWidget* projWidget_;
    CalenderWidget* calWidget_;
    DbMgr* dbmgr_;
};

#endif // MAINWINDOW_H
