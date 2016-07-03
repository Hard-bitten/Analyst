#ifndef LOGGER_H
#define LOGGER_H

#include <QtCore/QObject>
#include <QDebug>
//日志处理函数


//日志处理类
class logger: public QObject
{
    Q_OBJECT
public:
    ~logger(){}
    static logger *_instance;
    static logger *instance();

public:
    void loggerMaster(const QString & msg);
    void loggerMaster(const char *msg);
signals:
    void G_sndMsg(const QString &);

private:
    //将默认构造函数设置为私有
    logger(QObject *parent = 0):
        QObject(parent){}
};


#endif // LOGGER_H
