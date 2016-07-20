#include "select_dialog.h"
#include "options.h"
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QList>

SelectDialog::SelectDialog(QListWidget *List,QWidget *parent)
    : QDialog(parent)
{
    list=List;
    this->setWindowTitle( tr( "添加一个整理项目" ) );
    createWidgets();
}

/*-------------------------------------------------------------------*/
/*!

 */
void
SelectDialog::createWidgets()
{
    opt=new options;
    QVBoxLayout * top_layout = new QVBoxLayout();
    top_layout->setSizeConstraint( QLayout::SetFixedSize );
    commit=new QPushButton();
    commit->setText(tr("添加"));
    connect(commit,SIGNAL(clicked(bool)),this,SLOT(oncommit()));


    // show

        QVBoxLayout * layout = new QVBoxLayout();
        layout->setSizeConstraint( QLayout::SetFixedSize );
        layout->setMargin( 4 );
        layout->setSpacing( 4 );
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
        M_pos_cb->setChecked( opt->pos() );
        connect( M_pos_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickpos(bool) ) );
        layout->addWidget( M_pos_cb);
        //
        M_ang_cb = new QCheckBox( tr( "角度" ) );
        M_ang_cb->setChecked( opt->ang());
        connect( M_ang_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickang( bool ) ) );
        layout->addWidget( M_ang_cb );
        //
        M_MaxTurn_cb = new QCheckBox( tr( "最大转角" ) );
        M_MaxTurn_cb->setChecked( opt->MaxTurn() );
        connect( M_MaxTurn_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickMaxTurn( bool ) ) );
        layout->addWidget( M_MaxTurn_cb );
        //
        M_LastMove_cb = new QCheckBox( tr( "一周期位移" ) );
        M_LastMove_cb->setChecked( opt->LastMove() );
        connect( M_LastMove_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickLastMove (bool ) ) );
        layout->addWidget( M_LastMove_cb );
        top_layout->addLayout( layout );
        //
        M_Body_cb = new QCheckBox( tr( "身体方向" ) );
        M_Body_cb->setChecked( opt->LastMove() );
        connect( M_Body_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickBody (bool ) ) );
        layout->addWidget( M_Body_cb );
        top_layout->addLayout( layout );
        //
    }
    {
        QHBoxLayout * layout = new QHBoxLayout();
        layout->setMargin( 0 );
        layout->setSpacing( 0 );

        M_head_cb = new QCheckBox( tr( "身体方向" ) );
        M_head_cb->setChecked( opt->head() );
        connect( M_Body_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickhead (bool ) ) );
        layout->addWidget( M_head_cb );
        top_layout->addLayout( layout );
        //
        M_tackle_cb = new QCheckBox( tr( "铲球概率" ) );
        M_tackle_cb->setChecked( opt->tackle() );
        connect( M_tackle_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clicktackle(bool)));
        layout->addWidget( M_tackle_cb );
        top_layout->addLayout( layout );
        //
        M_Foul_cb = new QCheckBox( tr( "犯规概率" ) );
        M_Foul_cb->setChecked( opt->Foul() );
        connect( M_Foul_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickFoul(bool)));
        layout->addWidget( M_Foul_cb );
        top_layout->addLayout( layout );
        //
        M_pointto_cb = new QCheckBox( tr( "指向位置" ) );
        M_pointto_cb->setChecked( opt->pointto() );
        connect( M_pointto_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickpointto(bool)));
        layout->addWidget( M_pointto_cb );
        top_layout->addLayout( layout );
        //
        M_focus_cb = new QCheckBox( tr( "注意目标" ) );
        M_focus_cb->setChecked( opt->focus() );
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
        M_stamina_cb = new QCheckBox( tr( "体能值&体能池" ) );
        M_stamina_cb->setChecked( opt->stamina() );
        connect( M_stamina_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickstamina(bool)));
        layout->addWidget( M_stamina_cb );
        top_layout->addLayout( layout );
        //
        M_power_cb = new QCheckBox( tr( "力量" ) );
        M_power_cb->setChecked( opt->power() );
        connect( M_power_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickpower(bool)));
        layout->addWidget( M_power_cb );
        top_layout->addLayout( layout );
        //
        M_Recovery_cb = new QCheckBox( tr( "体力恢复值" ) );
        M_Recovery_cb->setChecked( opt->Recovery() );
        connect( M_Recovery_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickRecovery(bool)));
        layout->addWidget( M_Recovery_cb );
        top_layout->addLayout( layout );
        //
        M_card_Y_cb = new QCheckBox( tr( "黄牌" ) );
        M_card_Y_cb->setChecked( opt->card_Y() );
        connect( M_card_Y_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickcard_Y(bool)));
        layout->addWidget( M_card_Y_cb );
        top_layout->addLayout( layout );
        //
        M_card_R_cb = new QCheckBox( tr( "红牌" ) );
        M_card_R_cb->setChecked( opt->card_R() );
        connect( M_card_R_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickcard_R(bool)));
        layout->addWidget( M_card_R_cb );
        top_layout->addLayout( layout );
    }
    {
        QHBoxLayout * layout = new QHBoxLayout();
        layout->setMargin( 0 );
        layout->setSpacing( 0 );
        //
        M_ballRelPos_cb = new QCheckBox( tr( "相对球的距离" ) );
        M_ballRelPos_cb->setChecked( opt->ballRelPos() );
        connect( M_ballRelPos_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickballRelPos(bool)));
        layout->addWidget( M_ballRelPos_cb );
        top_layout->addLayout( layout );
        //
        M_ballRelVel_cb = new QCheckBox( tr( "相对球的方向" ) );
        M_ballRelVel_cb->setChecked( opt->ballRelVel() );
        connect( M_ballRelVel_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickballRelVel(bool)));
        layout->addWidget( M_ballRelVel_cb );
        top_layout->addLayout( layout );
        //
        M_states_cb = new QCheckBox( tr( "球员状态" ) );
        M_states_cb->setChecked( opt->states() );
        connect( M_states_cb, SIGNAL( clicked( bool ) ),
                 this, SLOT( clickstates(bool)));
        layout->addWidget( M_states_cb );
        top_layout->addLayout( layout );

    }


    group_box->setLayout( top_layout );
    return group_box;
}

/*-------------------------------------------------------------------*/
/*!

 */
QWidget *
SelectDialog::createObjectControls(){

    QGroupBox * group_box = new QGroupBox( tr( "挖掘对象" ) );

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
QWidget * SelectDialog::createteamDetailControls(){

}

void SelectDialog::clickpos( bool checked ){
    if ( opt->pos() != checked )
    {
        opt->togglepos();
        //qDebug("fun");//emit configured();
    }
}
void SelectDialog::clickang( bool checked ){
    if ( opt->ang()!= checked )
    {
        opt->toggleang();
        //qDebug("fun");//emit configured();
    }
}
void SelectDialog::clickMaxTurn( bool checked ){
    if ( opt->MaxTurn()!= checked )
    {
        opt->toggleMaxTurn();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickLastMove( bool checked ){
    if ( opt->LastMove()!= checked )
    {
        opt->toggleLastMove();
        //qDebug("fun");//emit configured();
    }

}

void SelectDialog::clickhead( bool checked ){
    if ( opt->head()!= checked )
    {
        opt->togglehead();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clicktackle( bool checked ){
    if ( opt->tackle()!= checked )
    {
        opt->toggletackle();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickFoul( bool checked ){
    if ( opt->Foul()!= checked )
    {
        opt->toggleFoul();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickpointto( bool checked ){
    if ( opt->pointto()!= checked )
    {
        opt->togglepointto();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickfocus( bool checked ){
    if ( opt->focus()!= checked )
    {
        opt->togglefocus();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickstamina( bool checked ){
    if ( opt->stamina()!= checked )
    {
        opt->togglestamina();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickpower( bool checked ){
    if ( opt->power()!= checked )
    {
        opt->togglepower();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickRecovery( bool checked ){
    if ( opt->Recovery()!= checked )
    {
        opt->toggleRecovery();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickballRelPos( bool checked ){
    if ( opt->ballRelPos()!= checked )
    {
        opt->toggleballRelPos();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickballRelVel( bool checked ){
    if ( opt->ballRelVel()!= checked )
    {
        opt->toggleballRelVel();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickstates( bool checked ){
    if ( opt->states()!= checked )
    {
        opt->togglestates();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickcard_Y( bool checked ){
    if ( opt->card_Y()!= checked )
    {
        opt->togglecard_Y();
        //qDebug("fun");//emit configured();
    }

}
void SelectDialog::clickcard_R( bool checked ){
    if ( opt->card_R()!= checked )
    {
        opt->togglecard_R();
        //qDebug("fun");//emit configured();
    }

}
    void SelectDialog::clickBody( bool checked ){
        if ( opt->Body()!= checked )
        {
            opt->toggleBody();
            //qDebug("fun");//emit configured();
        }

    }

void SelectDialog::oncommit(){
    QString str;
    str+=(M_unum_start->currentText()+"->"+M_unum_end->currentText());
    int i,j;
    if(!M_unum_start->currentText().contains("Team")&&!M_unum_end->currentText().contains("Team"))
    {
//         i=M_unum_start->currentText().at(1);
//         j=M_unum_end->currentText().at(1);
    }
//    opt->setunum(i,j);

    QList<QCheckBox *> allCheckboxs= this->findChildren<QCheckBox *>();
    foreach (QCheckBox *b, allCheckboxs) {
        if(b->isChecked()){
            str+=b->text()+";";
        }
    }
    list->addItem(str);
    qDebug("成功添加一条挖掘条件");
    this->close();
}
