#ifndef TABLES_H
#define TABLES_H

#include <QDialog>
#include "structure_player.h"

namespace Ui {
class tables;
}

class tables : public QDialog
{
    Q_OBJECT

public:
    explicit tables(QWidget *parent = nullptr);
    ~tables();
    std::map <QString, perc_stat_of_player> perc_stat_of_players;
    void stat();
private:
    Ui::tables *ui;
};

#endif // TABLES_H
