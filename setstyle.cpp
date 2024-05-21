#include "setstyle.h"

SetStyle::SetStyle(MainWindow *p): parent(p)
{
    parent->setStyleSheet("background-color: rgb(34, 10, 50);");
    parent->ui->pushButton_Home->setStyleSheet("border:solid");
}
