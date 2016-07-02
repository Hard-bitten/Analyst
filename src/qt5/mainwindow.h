#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "main_data.h"
#include "tec_data.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Tec_Data M_Tec_Data;

private slots:

    void on_input_sin_triggered();

    void on_input_dir_triggered();

private:
    MainData M_main_data;
    QString workfile;
    void countkick(std::vector< Player >  &player,int *count1);
    void PT();
    void Shoot();
    void openRCG( const QString & file_path );
    bool open_dir();
    bool open_single();
    void test();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
