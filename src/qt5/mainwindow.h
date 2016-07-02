#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tec_data.h"
#include "basedata.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow,public BaseData
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_input_sin_triggered();
    void on_input_dir_triggered();

private:
    Tec_Data M_tec_Data;
    QString workfile;
    void openRCG( const QString & file_path );
    bool open_dir();
    bool open_single();
    void test();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
