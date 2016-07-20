#include "process.h"
#include "options.h"
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QString>
#include <QObject>

process::process()
{

}

//初始化静态变量
process * process::_instance = 0;

//构建单实例日志对象
process * process::instance()
{
    if(!process::_instance)
        process::_instance = new process;
    return process::_instance;
}

bool process::openRCG( const QString & file_path )
{

    if ( ! QFile::exists( file_path ) )
    {
        qWarning()<<file_path<<" 打开失败！";
        return false;
    }


    if ( ! M_main_data.openRCG( file_path.toStdString() ) )
    {
        qWarning()<<file_path<<" 读取失败！";
        return false;
    }
    else
    {
        QFileInfo file(file_path);
        qDebug()<<"成功打开文件"<<file.fileName();
    }
    if ( M_main_data.viewHolder().monitorViewCont().empty() )
    {
        qWarning()<<file_path<<" 空的RCG文件！";
        return false;
    }
    return true;
}

bool process::dataSave(options& opt){
//    db.creatDB();
    std::vector< Player >  player;
    int cycle;
//    options &opt=options::instance();
            //creat table
//    createtable(std::vector<int>,QString,QStringList);
    for(M_main_data.setViewDataCycle(1);
        M_main_data.getCurrentViewData()->cycle() != M_main_data.getViewHolder().latestViewData()->cycle();
        M_main_data.setViewDataStepForward())
    {
        player=M_main_data.getCurrentViewData()->players();
        cycle=M_main_data.getCurrentViewData()->cycle();
        //save cycle

        //save single player data
        for ( std::vector< Player >::const_iterator p = player.begin();
              p != player.end();
              ++p/*,++i*/){

//            if(player->unum())//ex
//                continue;

            if(opt.stamina())//save staminna
            {

            }

            if(opt.pos())//save pos
            {
                double posx,posy;
//                posx=player->pos().x;

            }

            if(opt.ang())
            {

            }

            if(opt.ballRelPos())
            {

            }

            if(opt.ballRelVel())
            {

            }

            if(opt.card_R())
            {

            }

            if(opt.card_Y())
            {

            }

            if(opt.focus())
            {

            }

            if(opt.Foul())
            {

            }

            if(opt.head())
            {

            }

            if(opt.Body())
            {

            }

            if(opt.LastMove())
            {

            }

            if(opt.MaxTurn())
            {

            }

            if(opt.pointto())
            {

            }

            if(opt.power())
            {

            }

            if(opt.Recovery())
            {

            }

            if(opt.states())
            {

            }

            if(opt.tackle())
            {

            }

            //save team data

        }
        if(cycle==6000)
        {
            if(opt.score())//save score
            {
//                if(team="L")
//                    score = M_main_data.getCurrentViewData()->leftTeam().score();
//                if(team="R")
//                    score = M_main_data.getCurrentViewData()->rightTeam().score();

            }
        }
        //save pen tata
        if(cycle==8000)
        {
            if(opt.penMiss())
            {

            }
            if(opt.penScore())
            {

            }
        }
    }
}

