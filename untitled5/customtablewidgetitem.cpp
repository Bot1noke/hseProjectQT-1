#include "customtablewidgetitem.h"

CustomTableWidgetItem::CustomTableWidgetItem(const QString &text)
    : QTableWidgetItem(text) {}

bool CustomTableWidgetItem::operator<(const QTableWidgetItem &other) const {
    bool ok;
    double value1 = text().toDouble(&ok);
    if (ok) {
        double value2 = other.text().toDouble(&ok);
        if (ok) {
            return value1 < value2;
        }
    }
    return QTableWidgetItem::operator<(other);
}
