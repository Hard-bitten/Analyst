#ifndef OPTIONS_H
#define OPTIONS_H
#include <QDebug>
class options
{
private:
    //unum
    int unum_start,unum_end;

    //ball
    bool M_ball_pos;//球的绝对位置
    bool M_ball_vel;//球的绝对速度
    bool M_ball_lastMove;//球的最近位移

    //single player(by cycle)
    bool M_pos;//位置
    bool M_ang;//方向
    bool M_vel;//速度
    bool M_ballRelPos;//球的相对位置
    bool M_LastMove;//最近的移动
    bool M_MaxTurn;//最大转角
    bool M_Body;//身体方向
    bool M_head;//头的方向
    bool M_tackle;//铲球概率
    bool M_Foul;//犯规概率
    bool M_pointto;//指向位置
    bool M_focus;// 关注目标
    bool M_stamina;//体能值+体能池
    bool M_Recovery;//恢复
    bool M_states;//球员状态(执行动作&是否活着)
    bool M_power;//执行动作力量
    //from 6000cycle
    bool M_card_Y;//黄牌
    bool M_card_R;//红牌

    //match(from 6000cycle)
    bool M_playerDiff;//球员异构
    bool M_score;//分数
    bool M_penScore;//点球得分
    bool M_penMiss;//点球失分
    //count
    bool M_kickCount;
    bool M_dashCount;
    bool M_turnCount;
    bool M_catchCount;
    bool M_moveCount;
    bool M_turnNeckCount;
    bool M_changeViewCount;
    bool M_sayCount;
    bool M_tackleCount;
    bool M_pointtoCount;
    bool M_attentiontoCount;

public:

    options();

    void setUnum(int & i,int &j)
    {
        unum_start=i;
        unum_end=j;
//        qDebug()<<i<<"  "<<j;
    }


    //ball
    bool ball_pos() const {return M_ball_pos;}//球的绝对位置
    void toggleball_pos(){M_ball_pos=!M_ball_pos;}

    bool ball_vel() const {return M_ball_vel;}//球的绝对速度
    void toggle(){M_ball_vel=!M_ball_vel;}

    bool ball_lastMove() const {return M_ball_lastMove;}//球的最近位移
    void toggleball_lastMove(){M_ball_lastMove=!M_ball_lastMove;}

    void togglepos() { M_pos = ! M_pos; }
    bool pos() const { return M_pos; }

    void toggleang(){ M_ang = ! M_ang; }
    bool ang() const { return M_ang; }

    bool vel()const{return M_vel;}//速度
    void togglevel(){M_vel=!M_vel;}

    void toggleMaxTurn(){ M_MaxTurn = ! M_MaxTurn; }
    bool MaxTurn() const { return M_MaxTurn;; }

    void toggleLastMove(){ M_LastMove = ! M_LastMove; }
    bool LastMove() const { return M_LastMove; }

    void toggleBody(){ M_Body = ! M_Body; }
    bool Body() const { return M_Body; }

    void togglehead(){ M_head= ! M_head; }
    bool head() const { return M_head; }

    void toggletackle(){ M_tackle= ! M_tackle; }
    bool tackle() const { return M_tackle;}

    void toggleFoul(){ M_Foul= ! M_Foul; }
    bool Foul() const { return M_Foul;}

    void togglepointto(){ M_pointto= ! M_pointto; }
    bool pointto() const { return M_pointto;}

    void togglefocus(){ M_focus= ! M_focus; }
    bool focus() const { return M_focus;}

    void togglestamina(){ M_stamina= ! M_stamina; }
    bool stamina() const { return M_stamina;}

    void togglepower(){ M_power= ! M_power; }
    bool power() const { return M_power;}

    void toggleRecovery(){ M_Recovery= ! M_Recovery; }
    bool Recovery() const { return M_Recovery;}

    void toggleballRelPos(){ M_ballRelPos= ! M_ballRelPos; }
    bool ballRelPos() const { return M_ballRelPos;}

    void togglestates(){ M_states= ! M_states; }
    bool states() const { return M_states;}

    void togglescore(){ M_score= ! M_score; }
    bool score() const { return M_score;}

    void togglepenScore(){ M_penScore= ! M_penScore; }
    bool penScore() const { return M_penScore;}

    void togglepenMiss(){ M_penMiss= ! M_penMiss; }
    bool penMiss() const { return M_penMiss;}

    void togglecard_Y(){ M_card_Y= ! M_card_Y; }
    bool card_Y() const { return M_card_Y;}

    void togglecard_R(){ M_card_R= ! M_card_R; }
    bool card_R() const { return M_card_R;}

    void toggleplayerDiff(){M_playerDiff=!M_playerDiff;}
    bool playerDiff() const { return M_playerDiff;}//球员异构

    bool kickCount() const { return  M_kickCount;}
    void togglekickCount()  { M_kickCount=!M_kickCount;}

    bool dashCount() const { return M_dashCount ;}
    void toggledashCount()  { M_dashCount=!M_dashCount;}

    bool turnCount() const { return  M_turnCount;}
    void toggleturnCount(){M_turnCount=!M_turnCount;}

    bool catchCount() const { return  M_catchCount;}
    void togglecatchCount(){M_catchCount=!M_catchCount;}

    bool moveCount() const { return  M_moveCount;}
    void togglemoveCount(){M_moveCount=!M_moveCount;}

    bool turnNeckCount() const { return  M_turnNeckCount;}
    void toggleturnNeckCount(){M_turnNeckCount=!M_turnNeckCount;}

    bool changeViewCount() const { return M_changeViewCount ;}
    void togglechangeViewCount(){M_changeViewCount=!M_changeViewCount;}

    bool sayCount() const { return  M_sayCount;}
    void togglesayCount(){M_sayCount=!M_sayCount;}

    bool tackleCount() const { return  M_tackleCount;}
    void toggletackleCount(){M_tackleCount=!M_tackleCount;}

    bool pointtoCount() const { return  M_pointtoCount;}
    void togglepointtoCount(){M_pointtoCount=!M_pointtoCount;}

    bool attentiontoCount() const { return  M_attentiontoCount;}
    void toggleattentiontoCount(){M_attentiontoCount=!M_attentiontoCount;}
};

#endif // OPTIONS_H
