#ifndef MAINWINDOW_H
class MainWindow;
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;

private slots:
    void quit();



    void on_pushButton_Home_clicked();

    void on_pushButton_Tag_clicked();

private:
    int Home;
    int Tag;
    int Page;
};
#endif // MAINWINDOW_H
