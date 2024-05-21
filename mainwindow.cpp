#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->Quit_btn, &QPushButton::clicked, this, &MainWindow::quit);
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


