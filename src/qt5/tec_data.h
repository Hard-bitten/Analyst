#ifndef TEC_DATA_H
#define TEC_DATA_H
#include <map>
#include "basedata.h"

class Tec_Single_Data:public BaseData{
private:
    int M_Goal=0;//进球数
    int M_Shoots=0;//射门数
    int M_Assists=0;//助攻数
    double M_Shots_Suc_Rate=0;//射门成功率
    int M_Pass=0;//传球数
    double M_Pass_Suc_Rate=0;//传球成功率
public:
    void setGoal(int);
    void setShoots(int);
    void setAssists(int);
    void setSSR(double);
    void setPass(int);
    void setPSR(int);
    int Goal(){
        return M_Goal;
    }
    int Shoots(){
        return M_Shoots;
    }
    int Assists(){
        return M_Assists;
    }
    int SSR(){
        return M_Shots_Suc_Rate;
    }
    int Pass(){
        return M_Pass;
    }
    int PSR(){
        return M_Pass_Suc_Rate;
    }
    Tec_Single_Data();
};
class Tec_Data:public BaseData
{
private:
    std::map<int,Tec_Single_Data> LTeam;
    std::map<int,Tec_Single_Data> RTeam;

    int M_L_Possession_Time=0;//L控球时间
    int M_R_Possession_Time=0;//R控球时间

    int M_L_Shoots=0;//L射门数
    int M_R_Shoots=0;//R射门数
public:
    std::map<int,Tec_Single_Data> & Tec_LTeam (){
        return LTeam;
    }
    std::map<int,Tec_Single_Data> & Tec_RTeam (){
        return RTeam;
    }

    void calcPT();
    int PT(char T)
    {
        if(T=='L')
            return M_L_Possession_Time;
        else
            if(T=='R')
                return M_R_Possession_Time;
            else
                return 0;
    }

    void calcShoots();
    int Shoots(char T){
        if(T=='L')
            return M_L_Shoots;
        else
            if(T=='R')
                return M_R_Shoots;
            else
                return 0;
    }

};

#endif // TEC_DATA_H
