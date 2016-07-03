#ifndef PROCESS_H
#define PROCESS_H
#include "basedata.h"
#include "QDebug"

class process:public BaseData
{
private:
    void calcPT();
    void calcShoots();
    bool openRCG( const QString & file_path );
public:
    process();
    static process *_instance;
    static process *instance();

    bool run(QString &Game);
};

#endif // PROCESS_H
