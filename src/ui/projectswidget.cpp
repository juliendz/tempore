#include "projectswidget.h"
#include "ui_projectswidget.h"

ProjectsWidget::ProjectsWidget(QWidget *parent) : QWidget(parent), ui(new Ui::ProjectsWidget) {
    ui->setupUi(this);

    connect(ui->btn_AddProject, SIGNAL(clicked()), this, SLOT(show_add_project()));
}

ProjectsWidget::~ProjectsWidget() {
    delete ui;
}


void ProjectsWidget::refresh_projects() {
    DbMgr dbmgr;
    DB_QRES qres = dbmgr.run_select_query("SELECT * FROM Project");
    for (int i=0; i < qres->count(); i++) {
        DB_QROW row = qres->at(i);
        qDebug() << row['name'];
    }
}


void ProjectsWidget::show_add_project(){
    ProjectDialog* dialog = new ProjectDialog(this);
    dialog->exec();
}
