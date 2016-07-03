#include "process.h"
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

void process::calcPT()
{
    std::vector< Player >  player;
    char state=' ';
    char temp_S=' ';
    int temp=0;
    int time_L=0;
    int time_R=0;
    int count=0;
    for(M_main_data.setViewDataCycle(1);
        M_main_data.getCurrentViewData()->cycle() != M_main_data.getViewHolder().latestViewData()->cycle();
        M_main_data.setViewDataStepForward())
    {
        player=M_main_data.getCurrentViewData()->players();
        state=' ';
        for ( std::vector< Player >::const_iterator p = player.begin();
              p != player.end();
              ++p/*,++i*/){
            if(p->isKicking()){
                if(p->side()==1){
                    state='L';
                }
                if(p->side()==-1){
                    state='R';
                }
            }
        }
        if(state==' ')
            continue;
        if(state==temp_S){
            if(state=='L'){
                time_L+=M_main_data.getCurrentViewData()->cycle()-temp;
            }
            if(state=='R'){
                time_R+=M_main_data.getCurrentViewData()->cycle()-temp;
            }
            count++;
        }
        else{
            if(count>2){
                if(state=='R'){
                    time_L+=(M_main_data.getCurrentViewData()->cycle()-temp);
                }
                if(state=='L'){
                    time_R+=(M_main_data.getCurrentViewData()->cycle()-temp);
                }
            }
            count=0;
        }
        temp=M_main_data.getCurrentViewData()->cycle();
        temp_S=state;
    }
    qDebug()<<"L_Possession_Time:"<<time_L<<"  R_Possession_Time:"<<time_R;
    //    M_tec_Data->setPT('L',time_L);
    //    M_tec_Data->setPT('R',time_R);
    //    std::cerr<<<<std::endl;
}

void process::calcShoots()
{
    int L_Shoots=0;
    int R_Shoots=0;

    double xt,yt;
    double X;
    double Y;
    double X_v;
    double Y_v;

    const int cycle = 7;
    int t;
    int temp_t=0;
    t=cycle;
    for(M_main_data.setViewDataCycle(1);
        M_main_data.getCurrentViewData()->cycle() != M_main_data.getViewHolder().latestViewData()->cycle();
        M_main_data.setViewDataStepForward())
    {
        if(M_main_data.getCurrentViewData()->playmode().name()!="play_on"){
            continue;
        }
        X=M_main_data.getCurrentViewData()->ball().x();
        Y=M_main_data.getCurrentViewData()->ball().y();
        X_v=M_main_data.getCurrentViewData()->ball().deltaX();
        Y_v=M_main_data.getCurrentViewData()->ball().deltaY();
        if(abs(X)<36){
            continue;
        }
        xt=X;
        yt=Y;
        for(int m=1;m<=t;m++){
            X_v*=0.94;
            xt+=X_v;
        }
        for(int m=1;m<=t;m++){
            Y_v*=0.94;
            yt+=Y_v;
        }

        if(abs(xt)>52.5&&abs(yt)<8.5)
            //            if(abs(xt)>52.5&&abs(yt)<7.01)
        {
            if(t==temp_t){
                if(t==4){
                    if(X>0)
                        L_Shoots++;
                    else
                        R_Shoots++;
                    std::cerr<<M_main_data.getCurrentViewData()->cycle() <<": "<<t<<" "<<X<<" "<<Y<<" "<<X_v<<" "<<Y_v<<" "<<xt<<" "<<yt<<std::endl;
                    t=cycle;
                }
            }
            //            if(t!=temp_t)
            //            {
            //                t=cycle;
            //            }
            t--;
            temp_t=t;
        }
    }
    //    M_tec_Data->setShoots('L',L_Shoots);
    //    M_tec_Data->setShoots('R',R_Shoots);
    qDebug()<<"L_Shoots:"<<L_Shoots<<"   R_Shoots:"<<R_Shoots;
}

bool process::run(QString &Game){
    qDebug()<<"--------------------------------------------------------------------------------------";
    if(!openRCG(Game))
        return false;
    QString L_name,R_name;

    L_name.fromStdString(M_main_data.getViewHolder().latestViewData()->leftTeam().name());
    R_name.fromStdString(M_main_data.getViewHolder().latestViewData()->leftTeam().name());
    qDebug()<<"队名："<<L_name<<"--"<<R_name;

    int L_score,R_score;
    if(M_main_data.getViewHolder().latestViewData()->cycle()>6000){
        L_score=M_main_data.getViewHolder().latestViewData()->leftTeam().score();
        R_score = M_main_data.getViewHolder().latestViewData()->rightTeam().score();
        qDebug()<<"比分（有点球）:"<<L_score<<"--"<<R_score;
    }
    L_score= M_main_data.getViewHolder().getViewData(6000)->leftTeam().score();
    R_score= M_main_data.getViewHolder().getViewData(6000)->rightTeam().score();
    //    M_tec_Data->setGoal('L',L_score);
    //    M_tec_Data->setGoal('R',R_score);
    qDebug()<<"比分（无点球）:"<<L_score<<"--"<<R_score;
    calcPT();
    calcShoots();
    qDebug()<<"--------------------------------------------------------------------------------------";
    return true;

}
