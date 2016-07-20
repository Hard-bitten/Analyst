#ifndef DB_H
#define DB_H
#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include<QString>
#include<QStringList>
#include <QMap>
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
    bool creatTable(QStringList  v,QStringList list );
    bool update(int unum,QString item,QString value);
    bool update(int unum,QString item,int value);
    bool update(int unum,QString item,double value);

    bool insert(int &unum,QMap<QString item,QString value> *list);
    bool insert(int unum,QString item,int value);
    bool insert(int unum,QString item,double value);
};

#endif // DB_H
