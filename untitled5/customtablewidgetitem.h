#ifndef CUSTOMTABLEWIDGETITEM_H
#define CUSTOMTABLEWIDGETITEM_H

#include <QTableWidgetItem>

class CustomTableWidgetItem : public QTableWidgetItem
{
public:
    CustomTableWidgetItem(const QString &text);

    bool operator<(const QTableWidgetItem &other) const override;
};

#endif 
