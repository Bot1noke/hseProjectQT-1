#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QToolBar>
#include <QString>
#include <QHeaderView>
#include <map>
#include <vector>
#include "customtablewidgetitem.h"
#include "structure_player.h"
#include "players.h"

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //"Player Name", "Salary", "Position", "Age", "Team", "Games Played", "Games Started","Min/Game", "FG", "FGA", "3P", "3PA",
    //"2P", "2PA", "ORB", "DRB", "AST", "STL", "BLK", "PF", "PTS", "Total minutes", "PER"
    std::map <QString, player> players;
    std::map <QString, perc_stat_of_player> perc_stat_of_players;


private slots:
    void addPlayer();
    void deletePlayer();
    void uploadDataset();
    void openDataAnalysis();  // Add this line
private:
    Ui::MainWindow *ui;
    QTableWidget *tableWidget;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *uploadButton;
    QPushButton *dataAnalysisButton; // Add this line
    QToolBar *toolBar;

    void readCSV(const QString &filename);
    void writeCSV(const QString &filename);
    void sortData(int column);  // Add this line
};


#endif // MAINWINDOW_H
