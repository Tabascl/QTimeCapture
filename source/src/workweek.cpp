#include "workweek.h"
#include "ui_workweek.h"

WorkWeek::WorkWeek(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkWeek)
{
    ui->setupUi(this);
}

void WorkWeek::AddDay(WorkDay *day)
{
    ui->horizontalLayout->addWidget(day);
}

WorkWeek::~WorkWeek()
{
    delete ui;
}
