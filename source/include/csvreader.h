#ifndef CSVREADER_H
#define CSVREADER_H

#include <QList>
#include <QStringList>


class CSVReader
{
public:
    CSVReader(QChar splitCharacter, bool ignoreLineBreaks = true);
    QList<QStringList> read(QString csvString);
private:
    const QChar split_char;
    const bool ignore_line_breaks;
    void item_done(QStringList &row, QString &item);

};

#endif // CSVREADER_H
