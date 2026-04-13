#ifndef HANHVI_H
#define HANHVI_H
#include"Sach.h"
#include"Database.h"
#include"Data.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>   
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
class HanhVi{
private:
    Database_Sach& dbs;
    Database_Donhang& dbd;
public:
    HanhVi(Database_Sach &d, Database_Donhang &c);
    thoigian layThoigianHienTai();
    void Mua();
    void themsach();
    void timsachtheoten();
    void timsachtheotheloai();
    void timsachtheotacgia();
    void xoasach();
    void suagia();
    void thuesach();
    void xemLichsu();
    void ghiLichSu(string loai, string tenSach, int soLuong, double tongTien,int mahoadon);
};
#endif