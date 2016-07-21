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
    //unum
    unum_start=-1;
    unum_end=-1;

    //ball
    M_ball_pos=false;//球的绝对位置
    M_ball_vel=false;//球的绝对速度
    M_ball_lastMove=false;//球的最近位移

    //single player by cycle
    M_pos=false;//位置
    M_ang=false;//方向
    M_vel=false;//速度
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
    M_states=false;//球员状态
    M_card_Y=false;//黄牌
    M_card_R=false;//红牌

    //match (only from 6000 cycle)
    M_playerDiff=false;//球员异构
    M_score=false;//分数
    //count
    M_kickCount=false;
    M_dashCount=false;
    M_turnCount=false;
    M_catchCount=false;
    M_moveCount=false;
    M_turnNeckCount=false;
    M_changeViewCount=false;
    M_sayCount=false;
    M_tackleCount=false;
    M_pointtoCount=false;
    M_attentiontoCount=false;

    //(from 8000cycle)
    M_penScore=false;//点球得分
    M_penMiss=false;//点球失分
}

