#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <cmath>

//UNIT TEST
void MainWindow::test(){

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}

//Single file open
bool MainWindow::open_single(){
    workfile=QFileDialog::getOpenFileName();
    if(!workfile.isEmpty())
    {
        openRCG(workfile);
        return true;
    }
    else
        return false;
}

//Directory open
bool MainWindow::open_dir(){
    workfile=QFileDialog::getExistingDirectory();
    if(!workfile.isEmpty())
    {
        return true;
    }
    else
        return false;
}

/*-------------------------------------------------------------------*/
/*!

*/
void
MainWindow::openRCG( const QString & file_path )
{
    if ( ! QFile::exists( file_path ) )
    {
        std::cerr << "File [" << file_path.toStdString()
                  << "] does not exist."
                  << std::endl;
        return;
    }


    if ( ! M_main_data.openRCG( file_path.toStdString() ) )
    {
        QString err_msg = tr( "Failed to read [" );
        err_msg += file_path;
        err_msg += tr( "]" );
        QMessageBox::critical( this,
                               tr( "Error" ),
                               err_msg,
                               QMessageBox::Ok, QMessageBox::NoButton );
        this->setWindowTitle( tr( PACKAGE_NAME ) );
        return;
    }
    else
    {

    }

    if ( M_main_data.viewHolder().monitorViewCont().empty() )
    {
        QString err_msg = tr( "Empty log file [" );
        err_msg += file_path;
        err_msg += tr( "]" );
        QMessageBox::critical( this,
                               tr( "Error" ),
                               err_msg,
                               QMessageBox::Ok, QMessageBox::NoButton );
        this->setWindowTitle( tr( PACKAGE_NAME ) );
        return;
    }
}



void MainWindow::on_input_sin_triggered()
{
    open_single();
}

void MainWindow::on_input_dir_triggered()
{
    open_dir();
}
