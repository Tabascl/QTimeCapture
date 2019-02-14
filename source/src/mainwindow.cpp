#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDate>
#include <QPointer>

#include <csvimport.h>
#include <workday.h>
#include <workweek.h>
#include <dayentry.h>
#include <defaultentry.h>

namespace WeekDayHelpers {
    QDate StartOfWeek(QDate date)
    {
        auto dayOfWeek = date.dayOfWeek();
        return date.addDays(-(dayOfWeek-1));
    }

    QDate EndOfWeek(QDate date)
    {
        auto dayOfWeek = date.dayOfWeek();
        auto diff = 5 - dayOfWeek;
        return date.addDays(diff);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    auto today = QDate::currentDate();

    auto cwString = tr("CW") + QString::number(today.weekNumber());
    auto dateString = today.toString("dddd, dd.MM.yyyy");

    ui->setupUi(this);

    ui->cwLabel->setText(cwString);
    ui->todayLabel->setText(dateString);

    makeWeek();
}

void MainWindow::on_actionClose_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionImport_triggered()
{
    auto importDialog = new CSVImport(this);
    importDialog->show();
}

void MainWindow::makeWeek()
{
    auto today = QDate::currentDate();

    auto weekStart = WeekDayHelpers::StartOfWeek(today);
    auto weekEnd = WeekDayHelpers::EndOfWeek(today);

    for (int i = 0; i < weekStart.daysTo(weekEnd)+1; i++)
    {
        auto targetDay = weekStart.addDays(i);
        auto day = QPointer<WorkDay>(new WorkDay(targetDay));
        ui->weekLayout->addWidget(day);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
