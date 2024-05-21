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
    
    QObject::connect(ui->Quit_btn, &QPushButton::clicked, this, &MainWindow::quit);
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

