#include"Sach.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
void Sach::setTen(string t) { Sach::tenSach = t; }
void Sach::setTacGia(string tg) { Sach::tacGia = tg; }
void Sach::setNam(int n) { Sach::namXB = n; }
void Sach::setTheLoai(string tl) { theLoai = tl; }
void Sach::setGia(double g) { Sach::gia = g; }
void Sach::setSoLuong(int sl) { Sach::soluong = sl; }
string Sach::getTen() { return Sach::tenSach; }
string Sach::getTacGia() { return Sach::tacGia; }
int Sach::getNam() { return Sach::namXB; }
string Sach::getTheLoai() { return Sach::theLoai; }
double Sach::getGia() { return Sach::gia; }
int Sach::getSoLuong() { return Sach::soluong; }
void Sach::input() {
    cout << "Ten sach: ";
    getline(cin, tenSach);
    cout << "Tac gia: ";
    getline(cin, tacGia);
    cout << "Nam XB: ";
    cin >> namXB;
    cout << "So luong: ";
    cin >> soluong;
    cin.ignore();
    cout << "The loai: ";
    getline(cin, theLoai);
    cout << "Gia: ";
    cin >> gia;
    cin.ignore();
}