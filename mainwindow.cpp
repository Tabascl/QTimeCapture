#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <csvimport.h>

#include <QDateTime>

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
}

MainWindow::~MainWindow()
{
    delete ui;
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
