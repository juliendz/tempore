#ifndef PROJECTDIALOG_H
#define PROJECTDIALOG_H

#include <QDialog>
#include <QHash>
#include <QDateTime>
#include "../db/dbmgr.h"

namespace Ui {
class ProjectDialog;
}

class ProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectDialog(QWidget *parent = 0);
    ~ProjectDialog();

public slots:
    void add_project();

private:
    Ui::ProjectDialog *ui;
};

#endif // PROJECTDIALOG_H
