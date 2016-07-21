#ifndef SELECT_DIALOG_H
#define SELECT_DIALOG_H
#include <QtGui>
#include <QObject>
#include <QCheckBox>
#include <QDialog>
#include <QTabWidget>
#include <QGroupBox>
#include <QComboBox>
#include <QListWidget>
#include <QQueue>
#include "options.h"
#include "process.h"
class SelectDialog:public QDialog
{
    Q_OBJECT

    options opt;
    QQueue<options> *opts;
    QComboBox * M_unum_start;
    QComboBox * M_unum_end;

    QPushButton * commit;
    QListWidget *list;
    //ball
    QCheckBox *  M_ball_pos_cb;//球的绝对位置
    QCheckBox *  M_ball_vel_cb;//球的绝对速度
    QCheckBox *  M_ball_lastMove_cb;//球的最近位移

    QCheckBox *  M_pos_cb;//位置
    QCheckBox *  M_ang_cb;//角度
    QCheckBox *  M_vel_cb;//速度
    QCheckBox *  M_MaxTurn_cb;//最大转角
    QCheckBox *  M_LastMove_cb;//最近的移动
    QCheckBox *  M_Body_cb;//身体角度
    QCheckBox *  M_head_cb;//头的方向
    QCheckBox *  M_tackle_cb;//铲球概率
    QCheckBox *  M_Foul_cb;//犯规概率
    QCheckBox *  M_pointto_cb;//指向位置
    QCheckBox *  M_focus_cb;// 关注
    QCheckBox *  M_stamina_cb;//体能值+体能池
    QCheckBox *  M_power_cb;//力量
    QCheckBox *  M_Recovery_cb;//恢复
    QCheckBox *  M_ballRelPos_cb;//球的相对距离
    QCheckBox *  M_states_cb;//球员状态
    QCheckBox *  M_card_Y_cb;//黄牌
    QCheckBox *  M_card_R_cb;//红牌

    //match(from 6000cycle)
    QCheckBox * M_playerDiff_cb;//球员异构
    QCheckBox * M_score_cb;//分数
    QCheckBox * M_penScore_cb;//点球得分
    QCheckBox * M_penMiss_cb;//点球失分
    //count
    QCheckBox * M_kickCount_cb;
    QCheckBox * M_dashCount_cb;
    QCheckBox * M_turnCount_cb;
    QCheckBox * M_catchCount_cb;
    QCheckBox * M_moveCount_cb;
    QCheckBox * M_turnNeckCount_cb;
    QCheckBox * M_changeViewCount_cb;
    QCheckBox * M_sayCount_cb;
    QCheckBox * M_tackleCount_cb;
    QCheckBox * M_pointtoCount_cb;
    QCheckBox * M_attentiontoCount_cb;


private slots:
    //ball
    void clickball_pos( bool checked );///球的绝对位置
    void clickball_vel( bool checked );///球的绝对速度
    void clickball_lastMove( bool checked );///球的最近位移

    void clickpos( bool checked );//位置
    void clickang( bool checked );//角度
    void clickvel( bool checked );//速度
    void clickMaxTurn( bool checked );//最大转角
    void clickLastMove( bool checked );//最近的移动
    void clickBody( bool checked );//身体角度
    void clickhead( bool checked );//头的方向
    void clicktackle( bool checked );//铲球概率
    void clickFoul( bool checked );//犯规概率
    void clickpointto( bool checked );//指向位置
    void clickfocus( bool checked );// 关注
    void clickstamina( bool checked );//体能值+体能池
    void clickpower( bool checked );//力量
    void clickRecovery( bool checked );//恢复
    void clickballRelPos( bool checked );//球的相对距离
    void clickstates( bool checked );//球员状态
    void clickcard_Y( bool checked );//黄牌
    void clickcard_R( bool checked );//红牌

    //match(from 6000cycle)
    void clickplayerDiff( bool checked );//球员异构
    void clickscore( bool checked );//分数
    void clickpenScore( bool checked );//点球得分
    void clickpenMiss( bool checked );//点球失分
    //count
    void clickkickCount( bool checked );
    void clickdashCount( bool checked );
    void clickturnCount( bool checked );
    void clickcatchCount( bool checked );
    void clickmoveCount( bool checked );
    void clickturnNeckCount( bool checked );
    void clickchangeViewCount( bool checked );
    void clicksayCount( bool checked );
    void clicktackleCount( bool checked );
    void clickpointtoCount( bool checked );
    void clickattentiontoCount( bool checked );

    void oncommit();

    void createWidgets();
    QWidget * createObjectControls();
    QWidget * createBallControls();
    QWidget * createTeamControls();
    QWidget * createPlayersDetailControls();
public:
    SelectDialog(QListWidget *List,QQueue<options> * _opts,QWidget *parent = 0 );

signals:
    void configured();
};

#endif // SELECT_DIALOG_H
