#include "dialog.h"
#include "ui_dialog.h"
#include "tables.h"
#include "mainwindow.h"

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
    window.perc_stat_of_players;
    window.setWindowTitle("Tables");
    window.exec();
}

