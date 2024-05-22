#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Home = 0;
    Tag = 1;
    ui->setupUi(this);
    setStyleSheet(readFile(":/style/style.qss"));
    QObject::connect(ui->Quit_btn, &QPushButton::clicked, this, &MainWindow::quit);
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::add);
    ui->stackedWidget->setCurrentIndex(Home);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quit()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Qt with SuperChicken", "Are you sure to close the window?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        qDebug() << "quit" ; //remember to save file in the future
        QApplication::quit();
    }
    
}






void MainWindow::on_pushButton_Home_clicked()
{
    ui->stackedWidget->setCurrentIndex(Home);
}


void MainWindow::on_pushButton_Tag_clicked()
{
    ui->stackedWidget->setCurrentIndex(Tag);
}

void MainWindow::add()
{
    QString file  = "tasks.txt";
    QFile t(file);
    if(!t.open(QIODevice::WriteOnly | QIODevice::Append)){
        qDebug() << "cannot not open file";
        return;
    }
    QTextStream out(&t);
    QString information = "tasks information";
    out << information << "\n";
    t.close();
}
QString MainWindow::readFile(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "Cannot read the file.";
    }
    QString st = file.readAll();
    file.close();
    return st;
}

