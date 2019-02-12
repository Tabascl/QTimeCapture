#include "dayentry.h"
#include "ui_dayentry.h"

#include <QTime>

DayEntry::DayEntry(DefaultEntry ent, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DayEntry),
    entry(ent)
{
    ui->setupUi(this);
}

DayEntry::~DayEntry()
{
    delete ui;
}
