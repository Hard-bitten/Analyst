#include "select_dialog.h"
#include "options.h"
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QList>

SelectDialog::SelectDialog(QListWidget *List, QQueue<options> *_opts,QWidget *parent)
    : QDialog(parent)
{
    list=List;
    opts=_opts;
    //    qDebug()<<_opts->count();
    this->setWindowTitle( tr( "添加一个整理项目" ) );
    createWidgets();
}

/*-------------------------------------------------------------------*/
/*!

 */
void
SelectDialog::createWidgets()
{
    //    opt=new options;
    QVBoxLayout * top_layout = new QVBoxLayout();
    top_layout->setSizeConstraint( QLayout::SetFixedSize );
    commit=new QPushButton();
    commit->setText(tr("添加"));
    connect(commit,SIGNAL(clicked(bool)),this,SLOT(oncommit()));


    // show

    QVBoxLayout * layout = new QVBoxLayout();
    layout->setSizeConstraint( QLayout::SetFixedSize );
    layout->setMargin( 0 );
    layout->setSpacing( 0 );

    layout->addWidget( createBallControls(),
                       0, Qt::AlignLeft );
    layout->addWidget( createTeamControls(),
                       0, Qt::AlignLeft );
    layout->addWidget( createObjectControls(),
                       0, Qt::AlignLeft );
    layout->addWidget( createPlayersDetailControls(),
                       0, Qt::AlignLeft );
    layout->addWidget(commit,
                      0,Qt::AlignCenter);
    this->setLayout(layout);
}

/*-------------------------------------------------------------------*/
/*!

 */
QWidget *
SelectDialog::createPlayersDetailControls()
{

    QGroupBox * group_box = new QGroupBox( tr( "单个球员" ) );

    QVBoxLayout * top_layout = new QVBoxLayout();
    top_layout->setMargin( 1 );
    top_layout->setSpacing( 0 );

    {
        QHBoxLayout * layout = new QHBoxLayout();
        layout->setMargin( 0 );
        layout->setSpacing( 0 );

        //
        M_pos_cb = new QCheckBox( tr( "位置" ) );
        M_pos_cb->setChecked( opt.pos() );
        connect( M_pos_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickpos(bool) ) );
        layout->addWidget( M_pos_cb);
        //
        M_vel_cb = new QCheckBox( tr( "速度" ) );
        M_vel_cb->setChecked( opt.vel() );
        connect( M_vel_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickvel(bool) ) );
        layout->addWidget( M_vel_cb);
        //
        M_ang_cb = new QCheckBox( tr( "方向" ) );
        M_ang_cb->setChecked( opt.ang());
        connect( M_ang_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickang( bool ) ) );
        layout->addWidget( M_ang_cb );
        //
        M_ballRelPos_cb = new QCheckBox( tr( "球的相对位置" ) );
        M_ballRelPos_cb->setChecked( opt.ballRelPos() );
        connect( M_ballRelPos_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickballRelPos(bool)));
        layout->addWidget( M_ballRelPos_cb );
        //
        M_MaxTurn_cb = new QCheckBox( tr( "最大转角" ) );
        M_MaxTurn_cb->setChecked( opt.MaxTurn() );
        connect( M_MaxTurn_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickMaxTurn( bool ) ) );
        layout->addWidget( M_MaxTurn_cb );
        //
        M_LastMove_cb = new QCheckBox( tr( "位移" ) );
        M_LastMove_cb->setChecked( opt.LastMove() );
        connect( M_LastMove_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickLastMove (bool ) ) );
        layout->addWidget( M_LastMove_cb );
        top_layout->addLayout( layout );
    }

    {
        QHBoxLayout * layout = new QHBoxLayout();
        layout->setMargin( 0 );
        layout->setSpacing( 0 );


        //
        M_Body_cb = new QCheckBox( tr( "身体方向" ) );
        M_Body_cb->setChecked( opt.LastMove() );
        connect( M_Body_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickBody (bool ) ) );
        layout->addWidget( M_Body_cb );

        M_head_cb = new QCheckBox( tr( "头的方向" ) );
        M_head_cb->setChecked( opt.head() );
        connect( M_Body_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickhead (bool ) ) );
        layout->addWidget( M_head_cb );
        //
        M_pointto_cb = new QCheckBox( tr( "指向位置" ) );
        M_pointto_cb->setChecked( opt.pointto() );
        connect( M_pointto_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickpointto(bool)));
        layout->addWidget( M_pointto_cb );
        //
        M_focus_cb = new QCheckBox( tr( "注意目标" ) );
        M_focus_cb->setChecked( opt.focus() );
        connect( M_focus_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickfocus(bool)));
        layout->addWidget( M_focus_cb );
        top_layout->addLayout( layout );
    }

    {
        QHBoxLayout * layout = new QHBoxLayout();
        layout->setMargin( 0 );
        layout->setSpacing( 0 );

        //
        M_tackle_cb = new QCheckBox( tr( "铲球概率" ) );
        M_tackle_cb->setChecked( opt.tackle() );
        connect( M_tackle_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clicktackle(bool)));
        layout->addWidget( M_tackle_cb );
        //
        M_Foul_cb = new QCheckBox( tr( "犯规概率" ) );
        M_Foul_cb->setChecked( opt.Foul() );
        connect( M_Foul_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickFoul(bool)));
        layout->addWidget( M_Foul_cb );
        //
        M_stamina_cb = new QCheckBox( tr( "体能信息" ) );
        M_stamina_cb->setChecked( opt.stamina() );
        connect( M_stamina_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickstamina(bool)));
        layout->addWidget( M_stamina_cb );
        //
        M_Recovery_cb = new QCheckBox( tr( "体力恢复值" ) );
        M_Recovery_cb->setChecked( opt.Recovery() );
        connect( M_Recovery_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickRecovery(bool)));
        layout->addWidget( M_Recovery_cb );


        top_layout->addLayout( layout );

    }

    {
        QHBoxLayout * layout = new QHBoxLayout();
        layout->setMargin( 0 );
        layout->setSpacing( 0 );
        //
        M_states_cb = new QCheckBox( tr( "球员状态" ) );
        M_states_cb->setChecked( opt.states() );
        connect( M_states_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickstates(bool)));
        layout->addWidget( M_states_cb );
        //
        M_power_cb = new QCheckBox( tr( "力量" ) );
        M_power_cb->setChecked( opt.power() );
        connect( M_power_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickpower(bool)));
        layout->addWidget( M_power_cb );
        //
        M_card_Y_cb = new QCheckBox( tr( "黄牌" ) );
        M_card_Y_cb->setChecked( opt.card_Y() );
        connect( M_card_Y_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickcard_Y(bool)));
        layout->addWidget( M_card_Y_cb );
        //
        M_card_R_cb = new QCheckBox( tr( "红牌" ) );
        M_card_R_cb->setChecked( opt.card_R() );
        connect( M_card_R_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickcard_R(bool)));
        layout->addWidget( M_card_R_cb );

        top_layout->addLayout( layout );

    }


    group_box->setLayout( top_layout );
    return group_box;
}

/*-------------------------------------------------------------------*/
/*!

 */
QWidget *
SelectDialog::createObjectControls()
{

    QGroupBox * group_box = new QGroupBox( tr( "选择球员" ) );

    QHBoxLayout * top_layout = new QHBoxLayout();
    top_layout->setMargin( 1);
    top_layout->setSpacing(3 );
    QStringList unumlist;
    unumlist<<"Team L"<<"L1"<<"L2"<<"L3"<<"L4"<<"L5"<<"L6"<<"L7"<<"L8"<<"L9"<<"L10"<<"L11"
           <<"Team R"<<"R1"<<"R2"<<"R3"<<"R4"<<"R5"<<"R6"<<"R7"<<"R8"<<"R9"<<"R10"<<"R11";
    M_unum_start=new QComboBox;
    M_unum_end = new QComboBox;
    M_unum_start->addItems(unumlist);
    M_unum_end->addItems(unumlist);
    QLabel *_static1=new QLabel("起始目标");
    QLabel *_static2=new QLabel("结束目标");

    top_layout->addWidget(_static1);
    top_layout->addWidget((M_unum_start));
    top_layout->addSpacing(20);
    top_layout->addWidget(_static2);
    top_layout->addWidget((M_unum_end));
    group_box->setLayout( top_layout );

    return group_box;
}

void SelectDialog::clickpos( bool checked ){
    if ( opt.pos() != checked )
    {
        opt.togglepos();
        //qDebug("fun");//emit configured();
    }
}
void SelectDialog::clickang( bool checked ){
    if ( opt.ang()!= checked )
    {
        opt.toggleang();
        //qDebug("fun");//emit configured();
    }
}
void SelectDialog::clickvel( bool checked ){
    if ( opt.vel()!= checked )
    {
        opt.togglevel();
        //qDebug("fun");//emit configured();
    }
}
void SelectDialog::clickMaxTurn( bool checked ){
    if ( opt.MaxTurn()!= checked )
    {
        opt.toggleMaxTurn();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickLastMove( bool checked ){
    if ( opt.LastMove()!= checked )
    {
        opt.toggleLastMove();
        //qDebug("fun");//emit configured();
    }

}

void SelectDialog::clickhead( bool checked ){
    if ( opt.head()!= checked )
    {
        opt.togglehead();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clicktackle( bool checked ){
    if ( opt.tackle()!= checked )
    {
        opt.toggletackle();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickFoul( bool checked ){
    if ( opt.Foul()!= checked )
    {
        opt.toggleFoul();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickpointto( bool checked ){
    if ( opt.pointto()!= checked )
    {
        opt.togglepointto();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickfocus( bool checked ){
    if ( opt.focus()!= checked )
    {
        opt.togglefocus();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickstamina( bool checked ){
    if ( opt.stamina()!= checked )
    {
        opt.togglestamina();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickpower( bool checked ){
    if ( opt.power()!= checked )
    {
        opt.togglepower();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickRecovery( bool checked ){
    if ( opt.Recovery()!= checked )
    {
        opt.toggleRecovery();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickballRelPos( bool checked ){
    if ( opt.ballRelPos()!= checked )
    {
        opt.toggleballRelPos();
        //qDebug("fun");//emit configured();
    }

}

void SelectDialog::clickstates( bool checked ){
    if ( opt.states()!= checked )
    {
        opt.togglestates();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickcard_Y( bool checked ){
    if ( opt.card_Y()!= checked )
    {
        opt.togglecard_Y();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickcard_R( bool checked ){
    if ( opt.card_R()!= checked )
    {
        opt.togglecard_R();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickBody( bool checked ){
    if ( opt.Body()!= checked )
    {
        opt.toggleBody();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickball_pos( bool checked )
{

}///球的绝对位置
void SelectDialog::clickball_vel( bool checked )
{

}///球的绝对速度
void SelectDialog::clickball_lastMove( bool checked )
{

}///球的最近位移

//match(from 6000cycle)
void SelectDialog::clickplayerDiff( bool checked )
{

}//球员异构

void SelectDialog::clickscore( bool checked )
{

}//分数

void SelectDialog::clickpenScore( bool checked )
{

}//点球得分

void SelectDialog::clickpenMiss( bool checked )
{

}//点球失分
//count
void SelectDialog::clickkickCount( bool checked )
{

}
void SelectDialog::clickdashCount( bool checked )
{

}
void SelectDialog::clickturnCount( bool checked )
{

}
void SelectDialog::clickcatchCount( bool checked )
{

}
void SelectDialog::clickmoveCount( bool checked )
{

}
void SelectDialog::clickturnNeckCount( bool checked )
{

}
void SelectDialog::clickchangeViewCount( bool checked )
{

}
void SelectDialog::clicksayCount( bool checked )
{

}
void SelectDialog::clicktackleCount( bool checked )
{

}
void SelectDialog::clickpointtoCount( bool checked )
{

}
void SelectDialog::clickattentiontoCount( bool checked )
{

}
void SelectDialog::oncommit(){
    int start,end;
    if(M_unum_start->currentText().at(1).isNumber()&&M_unum_end->currentText().at(1).isNumber()){
        if(M_unum_start->currentText().at(0)=='L'){
            start=M_unum_start->currentText().mid(1).toInt();
        }
        if(M_unum_end->currentText().at(0)=='L'){
            end=M_unum_end->currentText().mid(1).toInt();
        }
        if(M_unum_start->currentText().at(0)=='R'){
            start=M_unum_start->currentText().mid(1).toInt()+11;
        }
        if(M_unum_end->currentText().at(0)=='R'){
            end=M_unum_end->currentText().mid(1).toInt()+11;
        }
    }
    if(M_unum_start->currentText()==M_unum_end->currentText()
            &&M_unum_start->currentText()=="Team L")
    {
        start=1;
        end=11;
    }
    if(M_unum_start->currentText()==M_unum_end->currentText()
            &&M_unum_start->currentText()=="Team R")
    {
        start=12;
        end=22;
    }
    if((M_unum_start->currentText()=="Team L"
        &&M_unum_end->currentText()=="Team R")||
            (M_unum_start->currentText()=="Team R"
             &&M_unum_end->currentText()=="Team L")
            )
    {
        start=1;
        end=22;
    }
    if(start>end)
    {
        int temp=start;
        start=end;
        end=temp;
    }
    opt.setUnum(start,end);
    QString str;
    str+=(M_unum_start->currentText()+"->"+M_unum_end->currentText());
    if(!M_unum_start->currentText().contains("Team")&&!M_unum_end->currentText().contains("Team"))
    {
        //         i=M_unum_start->currentText().at(1);
        //         j=M_unum_end->currentText().at(1);
    }
    //    opt.setunum(i,j);

    QList<QCheckBox *> allCheckboxs= this->findChildren<QCheckBox *>();
    foreach (QCheckBox *b, allCheckboxs) {
        if(b->isChecked()){
            str+=b->text()+";";
        }
    }
    list->addItem(str);
    opts->push_back(opt);
    qDebug("成功添加一条挖掘条件");
    this->close();
}

QWidget *
SelectDialog::createBallControls(){
    QGroupBox * group_box = new QGroupBox( tr( "球信息" ) );

    QVBoxLayout * top_layout = new QVBoxLayout();
    top_layout->setMargin( 1 );
    top_layout->setSpacing( 0 );

    {
        QHBoxLayout * layout = new QHBoxLayout();
        layout->setMargin( 0 );
        layout->setSpacing( 0 );

        //
        M_ball_pos_cb = new QCheckBox( tr( "球绝对位置" ) );
        M_ball_pos_cb->setChecked( opt.ball_pos() );
        connect( M_ball_pos_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickball_pos(bool) ) );
        layout->addWidget( M_ball_pos_cb);
        //
        M_ball_vel_cb = new QCheckBox( tr( "球绝对速度" ) );
        M_ball_vel_cb->setChecked( opt.ball_vel() );
        connect( M_ball_vel_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickball_vel(bool) ) );
        layout->addWidget( M_ball_vel_cb);
        //
        M_ang_cb = new QCheckBox( tr( "方向" ) );
        M_ang_cb->setChecked( opt.ang());
        connect( M_ang_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickball_vel( bool ) ) );
        layout->addWidget( M_ang_cb );
        //
        M_ball_lastMove_cb = new QCheckBox( tr( "绝对位移" ) );
        M_ball_lastMove_cb->setChecked( opt.ball_lastMove() );
        connect( M_ball_lastMove_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickball_lastMove (bool ) ) );
        layout->addWidget( M_ball_lastMove_cb );

        top_layout->addLayout( layout );
    }
    group_box->setLayout( top_layout );
    return group_box;
}
QWidget *
SelectDialog::createTeamControls(){
    QGroupBox * group_box = new QGroupBox( tr( "比赛信息" ) );

    QVBoxLayout * top_layout = new QVBoxLayout();
    top_layout->setMargin( 1 );
    top_layout->setSpacing( 0 );

    {
        QHBoxLayout * layout = new QHBoxLayout();
        layout->setMargin( 0 );
        layout->setSpacing( 0 );

        //
        M_playerDiff_cb = new QCheckBox( tr( "球员异构" ) );
        M_playerDiff_cb->setChecked( opt.playerDiff() );
        connect( M_playerDiff_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickplayerDiff(bool) ) );
        layout->addWidget( M_playerDiff_cb);
        //
        M_score_cb = new QCheckBox( tr( "分数" ) );
        M_score_cb->setChecked( opt.score() );
        connect( M_score_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickscore(bool) ) );
        layout->addWidget( M_score_cb);
        //
        M_penScore_cb = new QCheckBox( tr( "点球得分" ) );
        M_penScore_cb->setChecked( opt.penScore());
        connect( M_penScore_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickpenScore( bool ) ) );
        layout->addWidget( M_penScore_cb );
        //
        M_penMiss_cb = new QCheckBox( tr( "点球失分" ) );
        M_penMiss_cb->setChecked( opt.penMiss() );
        connect( M_penMiss_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickpenMiss (bool ) ) );
        layout->addWidget( M_penMiss_cb );

        top_layout->addLayout( layout );
    }
    {
        QHBoxLayout * layout = new QHBoxLayout();
        layout->setMargin( 0 );
        layout->setSpacing( 0 );

        //
        M_kickCount_cb = new QCheckBox( tr( "kick数" ) );
        M_kickCount_cb->setChecked( opt.kickCount() );
        connect( M_kickCount_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickkickCount(bool) ) );
        layout->addWidget( M_kickCount_cb);
        //
        M_dashCount_cb = new QCheckBox( tr( "dash数" ) );
        M_dashCount_cb->setChecked( opt.dashCount() );
        connect( M_dashCount_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickdashCount(bool) ) );
        layout->addWidget( M_dashCount_cb);
        //
        M_turnCount_cb = new QCheckBox( tr( "turn数" ) );
        M_turnCount_cb->setChecked( opt.turnCount());
        connect( M_turnCount_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickturnCount( bool ) ) );
        layout->addWidget( M_turnCount_cb );
        //
        M_catchCount_cb = new QCheckBox( tr( "catch数" ) );
        M_catchCount_cb->setChecked( opt.catchCount() );
        connect( M_catchCount_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickcatchCount (bool ) ) );
        layout->addWidget( M_catchCount_cb );
        //
        M_moveCount_cb = new QCheckBox( tr( "move数" ) );
        M_moveCount_cb->setChecked( opt.moveCount() );
        connect( M_moveCount_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickmoveCount(bool ) ) );
        layout->addWidget( M_moveCount_cb );

        top_layout->addLayout( layout );
    }
    {
        QHBoxLayout * layout = new QHBoxLayout();
        layout->setMargin( 0 );
        layout->setSpacing( 0 );

        //
        M_turnNeckCount_cb = new QCheckBox( tr( "turnNeck数" ) );
        M_turnNeckCount_cb->setChecked( opt.turnNeckCount() );
        connect( M_turnNeckCount_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickturnNeckCount(bool) ) );
        layout->addWidget( M_turnNeckCount_cb);
        //
        M_changeViewCount_cb = new QCheckBox( tr( "changeView数" ) );
        M_changeViewCount_cb->setChecked( opt.changeViewCount() );
        connect( M_changeViewCount_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickchangeViewCount(bool) ) );
        layout->addWidget( M_changeViewCount_cb);
        //
        M_sayCount_cb = new QCheckBox( tr( "say数" ) );
        M_sayCount_cb->setChecked( opt.sayCount());
        connect( M_sayCount_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clicksayCount( bool ) ) );
        layout->addWidget( M_sayCount_cb );
        //
        M_tackleCount_cb = new QCheckBox( tr( "tackle数" ) );
        M_tackleCount_cb->setChecked( opt.tackleCount() );
        connect( M_tackleCount_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clicktackleCount (bool ) ) );
        layout->addWidget( M_tackleCount_cb );

        top_layout->addLayout( layout );
    }
    {
        QHBoxLayout * layout = new QHBoxLayout();
        layout->setMargin( 0 );
        layout->setSpacing( 0 );

        //
        M_pointtoCount_cb = new QCheckBox( tr( "pointto数" ) );
        M_pointtoCount_cb->setChecked( opt.pointtoCount() );
        connect( M_pointtoCount_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickpointtoCount(bool) ) );
        layout->addWidget( M_pointtoCount_cb);
        //
        M_attentiontoCount_cb = new QCheckBox( tr( "attentionsto数" ) );
        M_attentiontoCount_cb->setChecked( opt.attentiontoCount() );
        connect( M_attentiontoCount_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickattentiontoCount(bool) ) );
        layout->addWidget( M_attentiontoCount_cb);

        top_layout->addLayout( layout );
    }
    group_box->setLayout( top_layout );
    return group_box;
}
