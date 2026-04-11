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
    Database& db;
public:
    staff(Database &d);
    void quanli();
};
class customer:public HanhVi,public Data{
    Database &db;
public:
    customer(Database &d);
    void thuchienmua();
};
class doituong:public staff,customer{
public:
    doituong(Database &d);
    void thuchien();
};
#endif