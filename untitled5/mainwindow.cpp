#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "tables.h"
#include <QFile>
#include <QTextStream>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QHeaderView>
#include "structure_player.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    tableWidget = new QTableWidget(this);
    setCentralWidget(tableWidget);
    tableWidget->setColumnCount(23);
    tableWidget->setHorizontalHeaderLabels({
        "Player Name", "Salary", "Position", "Age", "Team", "Games Played", "Games Started","Min/Game", "FG", "FGA", "3P", "3PA",
        "2P", "2PA", "ORB", "DRB", "AST", "STL", "BLK", "PF", "PTS", "Total minutes", "PER",
    });
    toolBar = new QToolBar(this);
    addToolBar(toolBar);
    addButton = new QPushButton("Add Player", this);
    deleteButton = new QPushButton("Delete Player", this);
    uploadButton = new QPushButton("Upload Dataset", this);
    dataAnalysisButton = new QPushButton("Data Analysis", this);
    uploadButton->setStyleSheet("background-color: red; color: white;");
    toolBar->addWidget(addButton);
    toolBar->addWidget(deleteButton);
    toolBar->addWidget(uploadButton);
    toolBar->addWidget(dataAnalysisButton);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addPlayer);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deletePlayer);
    connect(uploadButton, &QPushButton::clicked, this, &MainWindow::uploadDataset);
    connect(dataAnalysisButton, &QPushButton::clicked, this, &MainWindow::openDataAnalysis);

    tableWidget->setSortingEnabled(true); // Enable sorting

    connect(tableWidget->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::sortData);
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::readCSV(const QString &filename) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        int row = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            player p;
            p.sal = fields[1].toInt();
            p.pos = fields[2];
            p.age = fields[3].toInt();
            p.team = fields[4];
            p.gp = fields[5].toDouble();
            p.gs = fields[6].toDouble();
            p.mg = fields[7].toDouble();
            p.fg = fields[8].toDouble();
            p.fga = fields[9].toDouble();
            p.threeP = fields[10].toDouble();
            p.threePA = fields[11].toDouble();
            p.twoP = fields[12].toDouble();
            p.twoPA = fields[13].toDouble();
            p.orb = fields[14].toDouble();
            p.drb = fields[15].toDouble();
            p.ast = fields[16].toDouble();
            p.stl = fields[17].toDouble();
            p.blk = fields[18].toDouble();
            p.pf = fields[19].toDouble();
            p.pts = fields[20].toDouble();
            p.tm = fields[21].toInt();
            p.per = fields[22].toDouble();
            players[fields[0]] = p;
            perc_stat_of_player stat;
            stat.gs_gp = (p.gs / p.gp) * 100.0;
            stat.fg_fga = (p.fg / p.fga) * 100.0;
            stat.threeP_threePA = (p.threeP / p.threePA) * 100.0;
            stat.twoP_twoPA = (p.twoP / p.twoPA) * 100.0;
            perc_stat_of_players[fields[0]] = stat;
            tableWidget->insertRow(row);
            for (int col = 0; col < fields.size(); ++col) {
                tableWidget->setItem(row, col, new QTableWidgetItem(fields[col]));
                bool isNumber;
                fields[col].toDouble(&isNumber);
                if (isNumber) {
                    tableWidget->setItem(row, col, new CustomTableWidgetItem(fields[col]));
                } else {
                    tableWidget->setItem(row, col, new QTableWidgetItem(fields[col]));
                }
            }
            ++row;
        }
        file.close();
    }
}
void MainWindow::writeCSV(const QString &filename) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        for (int row = 0; row < tableWidget->rowCount(); ++row) {
            QStringList rowData;
            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                rowData << tableWidget->item(row, col)->text();
            }
            out << rowData.join(",") << "\n";
        }
        file.close();
    }
}
void MainWindow::addPlayer() {
    QStringList labels = {
        "Player Name", "Salary", "Position", "Age", "Team", "Games Played", "Games Started","Min/Game", "FG", "FGA", "3P", "3PA",
        "2P", "2PA", "ORB", "DRB", "AST", "STL", "BLK", "PF", "PTS", "Total minutes", "PER",
    };

    int row = tableWidget->rowCount();
    tableWidget->insertRow(row);
    std::vector<QString> fields;
    QString name;
    for (int col = 0; col < labels.size(); ++col) {
        QString value = QInputDialog::getText(this, "Add Player", labels[col] + ":");
        if (col == 0)
            name = value;
        else
            fields.push_back(value);
        tableWidget->setItem(row, col, new QTableWidgetItem(value));
        bool isNumber;
        value.toDouble(&isNumber);
        if (isNumber) {
            tableWidget->setItem(row, col, new CustomTableWidgetItem(value));
        } else {
            tableWidget->setItem(row, col, new QTableWidgetItem(value));
        }
    }
    player p;
    p.sal = fields[1].toInt();
    p.pos = fields[2];
    p.age = fields[3].toInt();
    p.team = fields[4];
    p.gp = fields[5].toDouble();
    p.gs = fields[6].toDouble();
    p.mg = fields[7].toDouble();
    p.fg = fields[8].toDouble();
    p.fga = fields[9].toDouble();
    p.threeP = fields[10].toDouble();
    p.threePA = fields[11].toDouble();
    p.twoP = fields[12].toDouble();
    p.twoPA = fields[13].toDouble();
    p.orb = fields[14].toDouble();
    p.drb = fields[15].toDouble();
    p.ast = fields[16].toDouble();
    p.stl = fields[17].toDouble();
    p.blk = fields[18].toDouble();
    p.pf = fields[19].toDouble();
    p.pts = fields[20].toDouble();
    p.tm = fields[21].toInt();
    p.per = fields[22].toDouble();
    players[name] = p;
    perc_stat_of_player stat;
    stat.gs_gp = p.gs / p.gp * 100;
    stat.fg_fga = p.fg / p.fga * 100;
    stat.threeP_threePA = p.threeP / p.threePA * 100;
    stat.twoP_twoPA = p.twoP / p.twoPA * 100;
    perc_stat_of_players[name] = stat;
    writeCSV("data.csv");
}



void MainWindow::deletePlayer() {
    int row = tableWidget->currentRow();
    QTableWidgetItem *firstItem = tableWidget->item(row, 0);
    players.erase(firstItem->text());
    perc_stat_of_players.erase(firstItem->text());
    if (row != -1) {
        tableWidget->removeRow(row);
        writeCSV("data.csv");
    } else {
        QMessageBox::warning(this, "Delete Player", "No player selected");
    }
}
void MainWindow::uploadDataset() {
    QString filename = QFileDialog::getOpenFileName(this, "Open CSV File", QDir::homePath() + "/Downloads", "CSV Files (*.csv)");
    if (!filename.isEmpty()) {
        tableWidget->setRowCount(0); // Clear existing rows
        readCSV(filename);
    }
}
void MainWindow::openDataAnalysis() {
    Dialog *dialog = new Dialog(this);
    dialog->setWindowTitle("DataAnalysis");
    dialog->perc_stat_of_players = perc_stat_of_players;
    dialog->players = players;
    dialog->exec();
}

void MainWindow::sortData(int column) {
    tableWidget->sortByColumn(column, tableWidget->horizontalHeader()->sortIndicatorOrder());
}
