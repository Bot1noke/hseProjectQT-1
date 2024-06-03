#include "tables.h"
#include "ui_tables.h"
#include <ui_mainwindow.h>
#include <QTableWidgetItem>
#include "structure_player.h"
#include <QString>

tables::tables(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tables)
{
    ui->setupUi(this);
}
void tables::stat()
{
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels({
        "Player Name", "GP/GS(%)", "FG/FGA(%)", "3P/3PA(%)", "2P/2PA(%)",
    });
    int row = 0;
    for (const auto& pair : perc_stat_of_players) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(pair.first));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(pair.second.gs_gp, 'f', 1)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(pair.second.fg_fga, 'f', 1)));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(pair.second.threeP_threePA, 'f', 1)));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(pair.second.twoP_twoPA, 'f', 1)));
        ++row;
    }
}
tables::~tables()
{
    delete ui;
}
