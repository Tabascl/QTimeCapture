#ifndef CSVIMPORT_H
#define CSVIMPORT_H

#include <QDialog>
#include <QFile>

namespace Ui {
class CSVImport;
}

class CSVImport : public QDialog
{
    Q_OBJECT

public:
    explicit CSVImport(QWidget *parent = nullptr);
    ~CSVImport();

private slots:
    void on_loadButton_clicked();

private:
    Ui::CSVImport *ui;
    void read_csv(QFile &file);
};

#endif // CSVIMPORT_H
