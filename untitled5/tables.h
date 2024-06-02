#ifndef TABLES_H
#define TABLES_H

#include <QDialog>

namespace Ui {
class tables;
}

class tables : public QDialog
{
    Q_OBJECT

public:
    explicit tables(QWidget *parent = nullptr);
    ~tables();
    struct perc_stat_of_player
    {
        double gs_gp;
        double fg_fga;
        double threeP_threePA;
        double twoP_twoPA;
    };
    std::map <QString, std::vector<perc_stat_of_player>> perc_stat_of_players;

private:
    Ui::tables *ui;
};

#endif // TABLES_H
