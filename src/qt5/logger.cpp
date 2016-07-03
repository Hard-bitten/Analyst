#include "logger.h"
#include<QTime>
//初始化静态变量
logger * logger::_instance = 0;

//构建单实例日志对象
logger * logger::instance()
{
    if(!logger::_instance)
        logger::_instance = new logger;
    return logger::_instance;
}


void logger ::loggerMaster(const QString & msg)
{
    //在日志信息中加入时间标记
    QString newLog = QDateTime::currentDateTime().toString(QLatin1String("MM-dd hh:mm:ss  "))
            + QLatin1Char(' ') + msg;
    //发送处理后的日志信息
    emit G_sndMsg(newLog);
}

void logger ::loggerMaster(const char * msg)
{
    //在日志信息中加入时间标记
    QString newLog = QDateTime::currentDateTime().toString(QLatin1String("MM-dd hh:mm:ss  "))
            + QLatin1Char(' ') + msg;
    //发送处理后的日志信息
    emit G_sndMsg(newLog);
}


//------------------------------------------日志处理部分结束
