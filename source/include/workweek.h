#ifndef WORKWEEK_H
#define WORKWEEK_H

#include <QWidget>

#include<workday.h>

namespace Ui {
class WorkWeek;
}

class WorkWeek : public QWidget
{
    Q_OBJECT

public:
    explicit WorkWeek(QWidget *parent = nullptr);

    void AddDay(WorkDay *day);

    ~WorkWeek();

private:
    Ui::WorkWeek *ui;
};

#endif // WORKWEEK_H
