#include"Database.h"
#include"Sach.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> 
#include <cstdlib>
#include <ctime>
using namespace std;
void Database_Sach::database_push(Sach s){
    dulieu.push_back(s);
}
void Database_Sach::database_show() {
cout << left
    << setw(35) << "Ten sach"
    << setw(25) << "Tac gia"
    << setw(8)  << "Nam"
    << setw(20) << "The loai"
    << setw(12) << "Gia"
    << setw(10) << "So luong"
    << endl;
cout << string(115, '-') << endl;
for (int i = 0; i < dulieu.size(); i++) {
    cout << left
        << setw(35) << dulieu[i].getTen()
        << setw(25) << dulieu[i].getTacGia()
        << setw(8)  << dulieu[i].getNam()
        << setw(20) << dulieu[i].getTheLoai()
        << setw(12) << fixed << setprecision(0) << dulieu[i].getGia()
        << setw(10) << dulieu[i].getSoLuong()
        << endl;
}
}
 int Database_Sach::getSizedatabase() {
    return dulieu.size();
}
 vector<Sach>& Database_Sach::getDulieu() {
    return dulieu;
}
void Database_Donhang::database_push(mahanghoa x)
{
    ma.push_back(x);
}
 vector<mahanghoa>& Database_Donhang::getDulieu(){
    return ma;
}
int Database_Donhang::getSizedatabase(){
    return ma.size();
}
void Database_Donhang::database_show(){
    for(int i = 0;i<ma.size();i++){
        cout << "===== HOA DON XUAT =====\n";
        cout << "Ma hoa don: "<<ma[i].id_donhang<<endl;
        cout << "Ten sach: " << ma[i].ten << endl;
        cout << "So luong: " << ma[i].soluong << endl;
        cout << "Don gia:  " << fixed << setprecision(0) << ma[i].dongia << endl;
        cout << "------------------------\n";
        cout << "TONG TIEN: " << fixed << setprecision(0) << ma[i].tien << " VND\n";
        cout << "Giao dich thanh cong! So luong ton kho da duoc cap nhat.\n";
    }
}