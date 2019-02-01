#include "csvimport.h"
#include "ui_csvimport.h"

#include <csvreader.h>

#include <QTextStream>
#include <QFileDialog>
#include <QStandardPaths>
#include <QStringList>

CSVImport::CSVImport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSVImport)
{
    ui->setupUi(this);
}

CSVImport::~CSVImport()
{
    delete ui;
}

void CSVImport::on_loadButton_clicked()
{
    auto docDir = QStandardPaths::locate(QStandardPaths::DocumentsLocation, QString(), QStandardPaths::LocateDirectory);
    auto fileName = QFileDialog::getOpenFileName(this,
                                                 tr("Open CSV"), docDir, tr("CSV Files (*.csv)"));
    QFile file(fileName);
    read_csv(file);
}

void CSVImport::read_csv(QFile &file)
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);

    auto rawCsv = in.readAll();
    CSVReader rd(';');
    auto csvData = rd.read(rawCsv);

    auto headers = csvData.at(0);
    ui->csvTable->setColumnCount(headers.size());
    ui->csvTable->setHorizontalHeaderLabels(headers);
    csvData.removeAt(0);

    for (int row = 0; row < csvData.size(); row++)
    {
        ui->csvTable->setRowCount(row + 1);
        auto rowData = csvData.at(row);
        for (int col = 0; col < headers.size(); col++)
        {
            auto *item = new QTableWidgetItem(rowData.at(col));
            ui->csvTable->setItem(row, col, item);
        }
    }

    ui->csvTable->resizeColumnsToContents();
}
