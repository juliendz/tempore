#ifndef PROJECTSWIDGET_H
#define PROJECTSWIDGET_H

#include <QWidget>
#include "projectdialog.h"
#include "../db/dbmgr.h"

namespace Ui {
class ProjectsWidget;
}

class ProjectsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectsWidget(QWidget *parent = 0);
    ~ProjectsWidget();

public slots:
    void refresh_projects();
    void show_add_project();

private:
    Ui::ProjectsWidget *ui;
};

#endif // PROJECTSWIDGET_H
