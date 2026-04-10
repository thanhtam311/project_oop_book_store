#include"main.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>   
#include <iomanip>
int main()
{
    Database db;
    Data ld(db);
    ld.Laydata("danh_sach_sach.txt");
    db.database_show();
    ld.xuatdata();
    return 0;
}