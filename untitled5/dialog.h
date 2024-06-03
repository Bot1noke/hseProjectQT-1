#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "structure_player.h"
#include "players.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    std::map <QString, perc_stat_of_player> perc_stat_of_players;
    std::map <QString, player> players;
private slots:

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
};

#endif
