#ifndef DAYENTRY_H
#define DAYENTRY_H

#include <QFrame>

#include <defaultentry.h>

namespace Ui {
class DayEntry;
}

class DayEntry : public QFrame
{
    Q_OBJECT

public:
    explicit DayEntry(DefaultEntry entry, QWidget *parent = nullptr);
    ~DayEntry();

private:
    Ui::DayEntry *ui;

    DefaultEntry entry;
};

#endif // DAYENTRY_H
