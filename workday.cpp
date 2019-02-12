#include "workday.h"
#include "ui_workday.h"

WorkDay::WorkDay(QDate date, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkDay),
    date(date)
{
    ui->setupUi(this);

    QString dayString(date.toString("dddd, dd"));

    ui->groupBox->setTitle(dayString);
}

void WorkDay::AddEntry(DayEntry *entry)
{
    ui->entryLayout->addWidget(entry);
}

WorkDay::~WorkDay()
{
    delete ui;
}
