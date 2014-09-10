#include "projectdialog.h"
#include "ui_projectdialog.h"

ProjectDialog::ProjectDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ProjectDialog) {
    ui->setupUi(this);
    connect(ui->btnbox_Main, SIGNAL(accepted()), this, SLOT(add_project()));
    connect(ui->btnbox_Main, SIGNAL(rejected()), this, SLOT(reject()));
}

ProjectDialog::~ProjectDialog() {
    delete ui;
}


void ProjectDialog::add_project(){
    QString name = ui->txtBox_Name->text();
    QString descr = ui->txtBox_Descr->text();
    QString tags = ui->txtBox_Tags->text();

    DbMgr dbmgr;
    QHash<QString , QVariant> args;
    args.insert(":name", name);
    args.insert(":descr", descr);
    args.insert(":created", QDateTime::currentDateTime().toTime_t());
    args.insert(":type", 0);
    args.insert(":status", 0);

    dbmgr.run_query("INSERT INTO Project (name, descr, created, type, status) "
                    "VALUES (:name, :descr, :created, :type, :status)",
                    args);

}
