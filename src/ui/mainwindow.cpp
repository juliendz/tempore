#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    dashWiget_ = new DashboardWidget(this);
    projWidget_ = new ProjectsWidget(this);
    calWidget_ = new CalenderWidget(this);

    ui->stackedWidget_Main->addWidget(dashWiget_);
    ui->stackedWidget_Main->addWidget(projWidget_);
    ui->stackedWidget_Main->addWidget(calWidget_);
    ui->stackedWidget_Main->setCurrentIndex(0);

    QObject::connect(ui->btn_Dash, SIGNAL(clicked()), this, SLOT(menu_change_to_dashboard()));
    QObject::connect(ui->btn_Proj, SIGNAL(clicked()), this, SLOT(menu_change_to_projects()));
    QObject::connect(ui->btn_Cal, SIGNAL(clicked()), this, SLOT(menu_change_to_calender()));

    QObject::connect(ui->stackedWidget_Main, SIGNAL(currentChanged(int)), this, SLOT(view_changed(int)));

    dbmgr_ = new DbMgr();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::view_changed(int index){
    if (index == 1) {
        projWidget_->refresh_projects();
    }
}


void MainWindow::menu_change_to_dashboard(){
    qDebug() << "Switch Dash view";
    ui->stackedWidget_Main->setCurrentIndex(0);
}


void MainWindow::menu_change_to_projects(){
    qDebug() << "Switch project view";
    ui->stackedWidget_Main->setCurrentIndex(1);
}



void MainWindow::menu_change_to_calender(){
    qDebug() << "Switch calender view";
    ui->stackedWidget_Main->setCurrentIndex(2);
}
