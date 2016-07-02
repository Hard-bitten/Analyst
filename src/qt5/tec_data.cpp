#include "tec_data.h"


void Tec_Data::calcPT()
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
    M_L_Possession_Time=time_L;
    M_R_Possession_Time=time_R;
    std::cerr<<"L_Possession_Time:"<<PT('L')<<"  R_Possession_Time:"<<PT('R')<<std::endl;
}

void Tec_Data::calcShoots()
{
    int L_Shoots=0;
    int R_Shoots=0;

    double xt,yt;
    double ax,ay;
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
    M_L_Shoots=L_Shoots;
    M_R_Shoots=R_Shoots;
    std::cerr<<"L_Shoots:"<<Shoots('L')<<"   R_Shoots:"<<Shoots('R')<<std::endl;
}

