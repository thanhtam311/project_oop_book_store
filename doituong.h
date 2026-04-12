#ifndef DOITUONG_H
#define DOITUONG_H
#include"Sach.h"
#include"Database.h"
#include"Data.h"
#include"hanhvi.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>   
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
class staff:public HanhVi,public Data{
    Database_Sach& db;
    Database_Donhang& dh;
public:
    staff(Database_Sach &d, Database_Donhang &x);
    void quanli();
};
class customer:public HanhVi,public Data{
    Database_Sach& db;
    Database_Donhang& dh;
public:
    customer(Database_Sach &d,Database_Donhang &x);
    void thuchienmua();
};
class renter : public HanhVi, public Data {
    Database_Sach& db;
    Database_Donhang& dh;
public:
    renter(Database_Sach &d,Database_Donhang &x);
    void thuchienthue();
};
class doituong:public staff,public customer, public  renter{
public:
    doituong(Database_Sach &d,Database_Donhang &x);
    void thuchien();
};
#endif