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
<<<<<<< HEAD
    Database_Sach dbs;
    Database_Donhang dbd;
    Data ld(dbs,dbd);
    ld.Laydata("danh_sach_sach.txt");
    dbs.database_show();
    ld.xuatdata();
    doituong dt(dbs,dbd);
=======
    Database_Sach db;
    Database_Donhang dh;
    Data ld(db);
    ld.Laydata("danh_sach_sach.txt");
    //db.database_show();
    ld.xuatdata();
    doituong dt(db, dh);
>>>>>>> cdaaae98db8e3a9db657e176635a8401bd9cfbc2
    dt.thuchien();
    return 0;
}