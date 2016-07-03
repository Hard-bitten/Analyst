#ifndef BASEDATA
#define BASEDATA

#include "tec_data.h"
#include "main_data.h"

class Tec_Data;
class BaseData{
public:
    MainData M_main_data;
    Tec_Data *M_tec_Data;
    friend class MainWindow;
    friend class process;
    BaseData(){}
};
#endif // BASEDATA
