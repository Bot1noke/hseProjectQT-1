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
    struct player
    {
        int sal;
        QString pos;
        int age;
        QString team;
        int gp;
        int gs;
        double mg;
        double fg;
        double fga;
        double threeP;
        double threePA;
        double twoP;
        double twoPA;
        double orb;
        double drb;
        double ast;
        double stl;
        double blk;
        double pf;
        double pts;
        int tm;
        double per;
    };
    std::map <QString, std::vector<player>> players;

    struct perc_stat_of_player
    {
        double gs_gp;
        double fg_fga;
        double threeP_threePA;
        double twoP_twoPA;
    };
    std::map <QString, std::vector<perc_stat_of_player>> perc_stat_of_players;

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
