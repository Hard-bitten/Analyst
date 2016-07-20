#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logger.h"
#include "select_dialog.h"
#include "namedialog.h"
#include <QLabel>
#include <QMenu>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QString>
#include <QDir>
#include <QDateTime>
#include <cmath>

//UNIT TEST
void MainWindow::test(){

}

//LogCatcher
void logCatcher(QtMsgType type,const QMessageLogContext& Context,const QString &msg)
{
    if(type == QtDebugMsg || type == QtWarningMsg)
        //将日志信息传递给logger处理函数
        logger::instance()->loggerMaster(msg);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //------------------------------------日志处理
    //注册日志处理函数
    qInstallMessageHandler(logCatcher);
    //连接日志，接收从logger实例中返回的日志信息
    connect(logger::instance(),SIGNAL(G_sndMsg(QString)),SLOT(S_disLog(QString)));
    Opts=new QQueue<options>;
    qDebug()<<"欢迎使用Analyst 1.0                                  by kaixuan！";

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Single file open
bool MainWindow::open_single(){
    QString filter;
    filter = "RCG file (*.rcg *.rcg.gz)";
    QDir dir;
    workfile=QFileDialog::getOpenFileName(NULL,QString("选取单个文件"), dir.absolutePath() , filter );
    if(!workfile.isEmpty())
    {
        //        openRCG(workfile);
        QListWidgetItem *temp=new QListWidgetItem(workfile);
        ui->tasklist->addItem(temp);
        temp->setCheckState(Qt::Checked);
        fileList<<workfile;
        qDebug()<<"成功导入1个RCG文件!";
        //        Pro.run(M_tec_Data);
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
        QDir *dir=new QDir(workfile);
        QStringList filter;
        filter<<"*.rcg"<<"*.rcg.gz";
        dir->setNameFilters(filter);
        QList<QFileInfo> *fileInfo=new QList<QFileInfo>(dir->entryInfoList(filter));
        int n=fileInfo->count();
        for(int i=0;i<n;i++){
            QListWidgetItem *temp=new QListWidgetItem(workfile+"/"+fileInfo->at(i).fileName());
            ui->tasklist->addItem(temp);
            temp->setCheckState(Qt::Checked);
            fileList<<(workfile+"/"+fileInfo->at(i).fileName());
        }
        qDebug()<<"成功导入"<<n<<"个文件";
        fillDBname();
        return true;
    }
    else
        return false;
}

//clicked on open_single
void MainWindow::on_input_sin_triggered()
{
    open_single();
}

//clicked on open_dir
void MainWindow::on_input_dir_triggered()
{
    open_dir();
}

//go to tab
void MainWindow::on_server_param_triggered()
{
    QString name=("服务器参数");
    QLabel *lable = new QLabel("server param!");
    new_tab(name,lable);
}

//creat a new tab
void MainWindow::new_tab(QString &text,QWidget *W){
    QTabWidget *form=ui->workform;
    int count = form->count();
    for(int i=0;i<count;i++){
        if(form->tabText(i)==text)
        {
            form->setCurrentIndex(i);
            return;//go to tab
        }
    }
    int new_index=form->addTab(W,text);
    form->setCurrentIndex(new_index);
}

//
void MainWindow::on_workform_tabBarDoubleClicked(int index)
{
    QTabWidget *form=ui->workform;
    if(form->tabText(index)=="主页")
    {
        return;
    }
    else
        form->currentWidget()->deleteLater();
}

void MainWindow::on_run_clicked()
{
//    QString temp;
    QList<QString>::iterator it=fileList.begin();
    process *curPro;
    for(;it!=fileList.end();it++){
        for(QQueue<options>::iterator i=Opts->begin();i!=Opts->end();i++){
            curPro=new process(*it,*i);
            if(curPro->run())
                qDebug()<<"为"<<*it<<"文件处理1条任务!";
        }
    }
}

//将日志信息追加到QPlainTextEdit控件中
void MainWindow::S_disLog(const QString & msg)
{
    ui->plainTextEdit->appendPlainText(msg);
}

void MainWindow::on_player_param_triggered()
{
    QString name=("球员参数");
    QLabel *lable = new QLabel("球员参数!");
    new_tab(name,lable);
}

void MainWindow::on_pushButton_clicked()
{
    SelectDialog *M_Select_Dialog=new SelectDialog(ui->objlist,Opts);
    M_Select_Dialog->show();
//    Pro->push_back(newpro);
}

void  MainWindow::fillDBname(){
    NameDialog *dbname=new NameDialog;
    dbname->exec();
    QString name=dbname->getname();
    name+=".db";
    delete dbname;
    qDebug()<<"成功创建"<<name;
    db=new Rcsdb;
    db->creatDB(name);
}
