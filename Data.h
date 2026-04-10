#ifndef DATA_H
#define DATA_H
#include"Database.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>   
#include <iomanip>
using namespace std;
class Data{
    Database &ds;
public:
    Data(Database &db);
    void Laydata(std::string filename);
    void xuatdata();
};
#endif