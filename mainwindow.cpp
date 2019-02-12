#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>

#include <csvimport.h>
#include <workday.h>
#include <workweek.h>
#include <dayentry.h>
#include <defaultentry.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    auto today = QDateTime::currentDateTime().date();

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
    auto day1 = new WorkDay(QDate(2019, 02, 01), this);
    auto day2 = new WorkDay(QDate(2019, 02, 02), this);
    auto day3 = new WorkDay(QDate(2019, 02, 03), this);
    auto day4 = new WorkDay(QDate(2019, 02, 04), this);
    auto day5 = new WorkDay(QDate(2019, 02, 05), this);

    auto dentry = DefaultEntry();
    auto entry1 = new DayEntry(dentry, this);

    day1->AddEntry(entry1);

    ui->weekLayout->addWidget(day1);
    ui->weekLayout->addWidget(day2);
    ui->weekLayout->addWidget(day3);
    ui->weekLayout->addWidget(day4);
    ui->weekLayout->addWidget(day5);
}

MainWindow::~MainWindow()
{
    delete ui;
}
