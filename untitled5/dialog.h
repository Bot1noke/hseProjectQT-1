#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    struct perc_stat_of_player
    {
        double gs_gp;
        double fg_fga;
        double threeP_threePA;
        double twoP_twoPA;
    };
    std::map <QString, std::vector<perc_stat_of_player>> perc_stat_of_players;
private slots:

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
};

#endif
