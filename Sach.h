#ifndef SACH_H
#define SACH_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
class Sach{
private:
    string tenSach;
    string tacGia;
    int namXB;
    int soluong;
    string theLoai;
    double gia;
public:
    void setTen(string t);
    void setTacGia(string tg);
    void setNam(int n);
    void setTheLoai(string tl);
    void setGia(double g);
    void setSoLuong(int sl);
    string getTen();
    string getTacGia();
    int getNam();
    string getTheLoai();
    double getGia();
    int getSoLuong();
    void input();
};
#endif