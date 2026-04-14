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
    Database_Sach dbs;
    Database_Donhang dbd;
    Data ld(dbs,dbd);
    ld.Laydata("danh_sach_sach.txt");
    ld.xuatdata();
    doituong dt(dbs,dbd);
    dt.thuchien();
    return 0;
}