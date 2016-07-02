#ifndef BASEDATA
#define BASEDATA

#include <main_data.h>

class BaseData{
public:
    MainData M_main_data;
    friend class Tec_Single_Data;
    friend class Tec_Data;
    friend class MainWindow;
    BaseData(){}
};
#endif // BASEDATA
