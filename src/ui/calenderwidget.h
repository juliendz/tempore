#ifndef CALENDERWIDGET_H
#define CALENDERWIDGET_H

#include <QWidget>

namespace Ui {
class CalenderWidget;
}

class CalenderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalenderWidget(QWidget *parent = 0);
    ~CalenderWidget();

private:
    Ui::CalenderWidget *ui;
};

#endif // CALENDERWIDGET_H
