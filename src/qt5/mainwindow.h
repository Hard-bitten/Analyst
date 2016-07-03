#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tec_data.h"
#include "basedata.h"
#include "process.h"
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

    void on_server_param_triggered();

    void on_workform_tabBarDoubleClicked(int index);

    void on_run_clicked();
    void S_disLog(const QString & msg);

    void on_player_param_triggered();

private:
    process Pro;
    QString workfile;

    bool open_dir();
    bool open_single();
    void new_tab(QString &text,QWidget *W);
    void test();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
