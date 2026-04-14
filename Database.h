#ifndef DATABASE_H
#define DATABASE_H
#include"Sach.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
struct thoigian{
    int ngay;
    int thang;
    int nam;
    int gio;
    int phut;
    int giay;
};
struct mahanghoa{
    bool check;
    int id_donhang;
    string ten;
    int soluong;
    double dongia;
    double tien;
    thoigian tg;
};
class Database{
public:
    virtual void database_push(){;}
    virtual void database_show(){;}
    virtual int getSizedatabase(){;}
    virtual ~Database(){}
};
class Database_Sach:public Database{
private:
    vector<Sach> dulieu;
public:
    void database_push(Sach s);
    void database_show();
    int getSizedatabase();
    vector<Sach>& getDulieu();
};
class Database_Donhang:public Database{
    vector<mahanghoa> ma;
public:
    void database_push(mahanghoa x);
    void database_show();
    int getSizedatabase();
    vector<mahanghoa>& getDulieu();

};
#endif