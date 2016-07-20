#include "db.h"

bool Rcsdb::creatTable(QStringList  v,QStringList list )
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
    for(QList<QString>::iterator it=v.begin();it!=v.end();it++)
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

bool Rcsdb::insert(int unum,QString item,QString value)
{

}
bool Rcsdb::insert(int unum,QString item,int value)
{

}
bool Rcsdb::insert(int unum,QString item,double value)
{

}
