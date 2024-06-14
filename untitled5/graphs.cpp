#include "graphs.h"
#include "ui_graphs.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QProcess>
#include <QDir>
#include <QDebug>
#include <QFile>

graphs::graphs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graphs)
{
    ui->setupUi(this);

}
void graphs::graph()
{
    QDir projectDir(QCoreApplication::applicationDirPath());
    projectDir.cdUp(); // Перемещаемся на уровень выше, чтобы выйти из каталога MacOS
    projectDir.cdUp(); // Перемещаемся на уровень выше, чтобы выйти из Contents
    projectDir.cdUp(); // Перемещаемся на уровень выше, чтобы выйти из .app
    projectDir.cdUp();
    projectDir.cdUp();

    // Устанавливаем рабочую директорию на каталог, содержащий проект
    QDir::setCurrent(projectDir.absolutePath());
    qDebug() << "Current directory set to:" << QDir::currentPath();

    // Путь к интерпретатору Python
    QString pythonPath = "venv/bin/python3"; // Используем относительный путь, если python3 в PATH

    // Путь к скрипту
    QString scriptPath = projectDir.filePath("generate_plot.py");

    // Проверяем, что скрипт существует
    if (!QFile::exists(scriptPath)) {
        qDebug() << "Script not found at:" << scriptPath;
        return;
    }

    // Запускаем скрипт для генерации графика
    QProcess process;
    process.start(pythonPath, QStringList() << scriptPath);

    // Ждем завершения процесса
    if (!process.waitForFinished()) {
        qDebug() << "Failed to run generate_plot.py";
        qDebug() << process.errorString();
        return;
    }

    // Путь к файлу plot.png
    QString plotPath = projectDir.filePath("plot.png");

    // Проверяем, что файл plot.png существует
    if (!QFile::exists(plotPath)) {
        qDebug() << "plot.png does not exist";
        return;
    }

    // Устанавливаем QPixmap в ui->label
    QPixmap pixmap(plotPath);
    ui->label->setPixmap(pixmap);
    ui->label->setScaledContents(true); // Масштабируем содержимое метки для заполнения метки
}

graphs::~graphs()
{
    delete ui;
}
