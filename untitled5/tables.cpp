#include "tables.h"
#include "ui_tables.h"
#include <ui_mainwindow.h>
#include <QTableWidgetItem>

tables::tables(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tables)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels({
        "Player Name", "GP/GS(%)", "FG/FGA(%)", "3P/3PA(%)", "2P/2PA(%)",
    });
    int row = 0;
    for (const auto& pair : perc_stat_of_players) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(pair.first));
        for(int col = 0; col < pair.second.size(); ++col)
        {
            //ui->tableWidget->setItem(row, col + 1, new CustomTableWidgetItem(pair.second[col]));
        }
    }
}
// void MainWindow::readCSV(const QString &filename) {
//     QFile file(filename);
//     if (file.open(QIODevice::ReadOnly)) {
//         QTextStream in(&file);
//         int row = 0;
//         while (!in.atEnd()) {
//             QString line = in.readLine();
//             QStringList fields = line.split(",");
//             player p;
//             p.sal = fields[1].toInt();
//             p.pos = fields[2];
//             p.age = fields[3].toInt();
//             p.team = fields[4];
//             p.gp = fields[5].toInt();
//             p.gs = fields[6].toInt();
//             p.mg = fields[7].toDouble();
//             p.fg = fields[8].toDouble();
//             p.fga = fields[9].toDouble();
//             p.threeP = fields[10].toDouble();
//             p.threePA = fields[11].toDouble();
//             p.twoP = fields[12].toDouble();
//             p.twoPA = fields[13].toDouble();
//             p.orb = fields[14].toDouble();
//             p.drb = fields[15].toDouble();
//             p.ast = fields[16].toDouble();
//             p.stl = fields[17].toDouble();
//             p.blk = fields[18].toDouble();
//             p.pf = fields[19].toDouble();
//             p.pts = fields[20].toDouble();
//             p.tm = fields[21].toInt();
//             p.per = fields[22].toDouble();
//             players[fields[0]].push_back(p);
//             perc_stat_of_player stat;
//             stat.gs_gp = p.gs / p.gp * 100;
//             stat.fg_fga = p.fg / p.fga * 100;
//             stat.threeP_threePA = p.threeP / p.threePA * 100;
//             stat.twoP_twoPA = p.twoP / p.twoPA * 100;
//             perc_stat_of_players[fields[0]].push_back(stat);
//             tableWidget->insertRow(row);
//             for (int col = 0; col < fields.size(); ++col) {
//                 tableWidget->setItem(row, col, new QTableWidgetItem(fields[col]));
//                 bool isNumber;
//                 fields[col].toDouble(&isNumber);
//                 if (isNumber) {
//                     tableWidget->setItem(row, col, new CustomTableWidgetItem(fields[col]));
//                 } else {
//                     tableWidget->setItem(row, col, new QTableWidgetItem(fields[col]));
//                 }
//             }
//             ++row;
//         }
//         file.close();
//     }
// }
tables::~tables()
{
    delete ui;
}
