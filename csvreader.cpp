#include "csvreader.h"

CSVReader::CSVReader(QChar splitCharacter, bool ignoreLineBreaks)
    : split_char(splitCharacter)
    , ignore_line_breaks(ignoreLineBreaks)
{

}

QList<QStringList> CSVReader::read(QString csvString)
{
    QList<QStringList> dataList;
    QString cur_item;
    QStringList cur_row;
    bool inField = false;

    for (int i = 0; i < csvString.size(); i++)
    {
        QChar cur_char = csvString.at(i);

        // Item done if split char reached
        if (cur_char == split_char)
        {
            item_done(cur_row, cur_item);
            continue;
        }

        // If newline reached and not inside a field, the row is done
        if (cur_char == '\n' && !inField)
        {
            item_done(cur_row, cur_item);
            dataList.append(cur_row);
            cur_row.clear();
            continue;
        }

        // Possible start of field
        if (cur_char == '"')
        {
            // If following char is double-quote, it's an escape sequence
            if (csvString.at(i + 1) == '"')
            {
                cur_item.append('"');
                i++;
            }

            inField = !inField;
            continue;
        }

        // Possibly ignore line breaks
        if (ignore_line_breaks && cur_char == '\n')
        {
            cur_item.append(' ');
            continue;
        }

        cur_item.append(cur_char);
    }

    return dataList;
}

void CSVReader::item_done(QStringList &row, QString &item)
{
    row.append(item);
    item.clear();
}
