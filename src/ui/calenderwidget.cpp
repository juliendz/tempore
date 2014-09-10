#include "calenderwidget.h"
#include "ui_calenderwidget.h"

CalenderWidget::CalenderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalenderWidget)
{
    ui->setupUi(this);
}

CalenderWidget::~CalenderWidget()
{
    delete ui;
}
