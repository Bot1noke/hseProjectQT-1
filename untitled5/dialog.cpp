#include "dialog.h"
#include "ui_dialog.h"
#include "tables.h"
#include "structure_player.h"
#include "graphs.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    tables window;
    window.perc_stat_of_players = perc_stat_of_players;
    window.stat();
    window.resize(1000, 800);
    window.setWindowTitle("Tables");
    window.exec();
}

void Dialog::on_pushButton_clicked()
{
    graphs window;
    window.graph();
    window.resize(800, 600);
    window.setWindowTitle("Graphs");
    window.exec();
}

