#ifndef OPTIONS_H
#define OPTIONS_H
#include <vector>

class options
{
private:
    //unum
    std::vector<int> unum;
    //single player
    bool M_pos;//位置
    bool M_ang;//角度
    bool M_MaxTurn;//最大转角
    bool M_LastMove;//最近的移动
    bool M_Body;//身体角度
    bool M_head;//头的方向
    bool M_tackle;//铲球概率
    bool M_Foul;//犯规概率
    bool M_pointto;//指向位置
    bool M_focus;// 关注
    bool M_stamina;//体能值+体能池
    bool M_power;//力量
    bool M_Recovery;//恢复
    bool M_ballRelPos;//球的相对距离
    bool M_ballRelVel;//球的相对方向
    bool M_states;//球员状态
    bool M_card_Y;//黄牌
    bool M_card_R;//红牌

    //team
    bool M_score;
    bool M_penScore;
    bool M_penMiss;


public:

    options();
//    static
//    options & instance();
    void setunum(int i,int j)
    {
        int t=0;
        for(t=i;t<=j;t++)
        {
            unum.push_back(i);
        }
    }
    void setunum(int i)
    {
        unum.push_back(i);
    }

    void togglepos() { M_pos = ! M_pos; }
    bool pos() const { return M_pos; }

    void toggleang(){ M_ang = ! M_ang; }
    bool ang() const { return M_ang; }

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

    void toggleballRelVel(){ M_ballRelVel= ! M_ballRelVel; }
    bool ballRelVel() const { return M_ballRelVel;}

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

};

#endif // OPTIONS_H
