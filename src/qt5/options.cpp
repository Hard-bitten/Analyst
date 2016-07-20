#include "options.h"

/*-------------------------------------------------------------------*/
/*!
  singleton interface
*/
//options & options::instance()
//{
//    static options s_instance;
//    return s_instance;
//}

options::options()
{
    M_pos=false;//位置
    M_ang=false;//角度
    M_MaxTurn=false;//最大转角
    M_LastMove=false;//最近的移动
    M_Body=false;//身体角度
    M_head=false;//头的方向
    M_tackle=false;//铲球概率
    M_Foul=false;//犯规概率
    M_pointto=false;//指向位置
    M_focus=false;// 关注
    M_stamina=false;//体能值+体能池
    M_power=false;//力量
    M_Recovery=false;//恢复
    M_ballRelPos=false;//球的相对距离
    M_ballRelVel=false;//球的相对方向
    M_states=false;//球员状态
    M_card_Y=false;//黄牌
    M_card_R=false;//红牌

    //team
    M_score=false;
    M_penScore=false;
    M_penMiss=false;
}

