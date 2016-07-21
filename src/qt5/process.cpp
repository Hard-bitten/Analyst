#include "process.h"
#include "options.h"
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QString>
#include <QObject>


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

bool process::dataSave(){
    qDebug()<<"运行dataSave()!";
    std::vector< Player >  players;
    int cycle;

    //拼接字符串      QString Str="INSERT INFO "+temp0+temp1+"VELUES"+temp3;
//    "
//    INSERT INFO
//    sheet1                                 QString temp0;
//    (item0,item1,item2...)        QString temp1;
//    VELUES
//    (value0,value1,...)               QString temp2;
//    "
    QString temp1,temp2;

    {
//        temp1=new QString;
        temp1+="(";
        if(opt.stamina())//save staminna
        {
            temp1+="stamina,";
        }

        if(opt.pos())//save pos
        {
            temp1+="posx,";
            temp1+="posy,";
        }

        if(opt.ang())
        {
            temp1+="ang,";
        }

        if(opt.ballRelPos())
        {
            temp1+="ballRelPos,";
        }


        if(opt.card_R())
        {
            temp1+="card_Red,";
        }

        if(opt.card_Y())
        {
            temp1+="card_Yellow,";
        }

        if(opt.focus())
        {
            temp1+="focus,";
        }

        if(opt.Foul())
        {
            temp1+="Foul,";
        }

        if(opt.head())
        {
            temp1+="head,";
        }

        if(opt.Body())
        {
            temp1+="body,";
        }

        if(opt.LastMove())
        {
            temp1+="lastmove_x,";
            temp1+="lastmove_y,";
        }

        if(opt.MaxTurn())
        {
            temp1+="maxturn,";
        }

        if(opt.pointto())
        {
            temp1+="pointto_x,";
            temp1+="pointto_y,";
        }

        if(opt.power())
        {
            temp1+="power,";
        }

        if(opt.Recovery())
        {
            temp1+="recovery,";
        }

        if(opt.states())
        {
            temp1+="states,";
        }

        if(opt.tackle())
        {
            temp1+="tackle";
        }

        //save team data

        temp1+=")";
    }

    for(M_main_data.setViewDataCycle(1);
        M_main_data.getCurrentViewData()->cycle() != M_main_data.getViewHolder().latestViewData()->cycle();
        M_main_data.setViewDataStepForward())
    {
        players=M_main_data.getCurrentViewData()->players();
        cycle=M_main_data.getCurrentViewData()->cycle();
        //save cycle

        //save single player data
        temp2="";
        for ( std::vector< Player >::const_iterator p = players.begin();
              p != players.end();
              ++p){
            {
//                temp2=new QString;
                temp2="(";
                if(opt.stamina())//save staminna
                {

                }

                if(opt.pos())//save pos
                {
//                    double posx,posy;

                }

                if(opt.ang())
                {

                }

                if(opt.ballRelPos())
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

                temp2+=")";
            }
//            if(player->unum())
//                continue;

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
    return true;
}

bool process::run(){
    if(!openRCG(File_Path))
        return false;
    if(!dataSave())
        return false;
    return true;
}
