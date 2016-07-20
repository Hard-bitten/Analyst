#ifndef PROCESS_H
#define PROCESS_H
#include "basedata.h"
#include "options.h"
#include "QDebug"



class process:public BaseData
{
private:
//    void calcPT();
//    void calcShoots();
    QString File_Path;
    options opt;
    bool openRCG( const QString & file_path );
    bool dataSave();

    process(){}
public:
    process(QString &file,options &_opt){
        File_Path=file;
        opt=_opt;
    }
    bool run();

//    bool run(QString &Game);
};

#endif // PROCESS_H
