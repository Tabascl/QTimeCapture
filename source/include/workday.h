#ifndef WORKDAY_H
#define WORKDAY_H

#include <QWidget>
#include <QPushButton>

#include <QDate>
#include <dayentry.h>

namespace Ui {
class WorkDay;
}

class WorkDay : public QWidget
{
    Q_OBJECT

public:
    explicit WorkDay(QDate date, QWidget *parent = nullptr);

    void AddEntry(DayEntry *entry);

    ~WorkDay();

    QSharedPointer<QPushButton> addBtn;

private:
    Ui::WorkDay *ui;

    QDate date;
};

#endif // WORKDAY_H
