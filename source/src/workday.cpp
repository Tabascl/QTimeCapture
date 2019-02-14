#include "workday.h"
#include "ui_workday.h"

WorkDay::WorkDay(QDate date, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkDay),
    date(date)
{
    ui->setupUi(this);

    QString dayString(date.toString("dddd, dd"));

    ui->dayGroup->setTitle(dayString);

    QString styleSheet = "#dayGroup { border:%1px solid %2; font: bold; margin-top: 6px; } #dayGroup::title { subcontrol-origin: margin; left: 7px; padding: 0px 5px 0px 5px; }";

    if (date == QDate::currentDate())
        ui->dayGroup->setStyleSheet(styleSheet.arg("2", "maroon"));
    else
        ui->dayGroup->setStyleSheet(styleSheet.arg("1", "silver"));
}

void WorkDay::AddEntry(DayEntry *entry)
{
    ui->entryLayout->addWidget(entry);
}

WorkDay::~WorkDay()
{
    delete ui;
}
