#include"main.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>   
#include <iomanip>
#include <cstdlib>
#include <ctime>
int main()
{
    Database db;
    Data ld(db);
    ld.Laydata("danh_sach_sach.txt");
    db.database_show();
    ld.xuatdata();
    doituong dt(db);
    dt.thuchien();
    return 0;
}