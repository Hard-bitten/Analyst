#ifndef DB_H
#define DB_H
#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include<QString>
#include<QStringList>

class Rcsdb
{
private:
    QSqlDatabase db;
    QSqlQuery query;
public:
    Rcsdb(){

    }
    bool creatDB(QString &name){
        db =  QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(name);
        if (!db.open())
        {
            qDebug("数据库不能打开");
        }
        return true;
    }
    bool creatTable(std::vector<QString>  v,QStringList list )
    {
        if(!db.open())
        {
            qDebug()<<"Could not open file!";
            return false;
        }
        else
        {
            qDebug()<<"Open file: "<<db.databaseName()<<" sucessfully!"<<endl;
        }
        QString unum;
        for(std::vector<QString>::iterator it=v.begin();it!=v.end();it++)
        {

            unum=*it;
            QString z;
            z+="create table if not exists "+unum+"L1(cycle int PRIMEARY KEY";
            for(QList<QString>::iterator i=list.begin();i!=list.end();i++)
            {
                z+=","+*i+" REAL";
            }
            z+=")";
            if(query.exec(z)){
                qDebug()<<"为"<<unum<<"号球员创建数据表成功!";
//                return true;
            }else{
                qDebug()<<"创建表失败!";
//                return false;
            }
        }
    }
};

#endif // DB_H
