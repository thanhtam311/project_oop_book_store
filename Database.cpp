#include"Database.h"
#include"Sach.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
void Database::database_push(Sach s){
    dulieu.push_back(s);
}
void Database::database_show() {
cout << left
    << setw(35) << "Ten sach"
    << setw(25) << "Tac gia"
    << setw(8)  << "Nam"
    << setw(20) << "The loai"
    << setw(12) << "Gia"
    << setw(10) << "So luong"
    << setw(15) << "Ma don hang"
    << endl;
cout << string(125, '-') << endl;
for (int i = 0; i < dulieu.size(); i++) {
    cout << left
        << setw(35) << dulieu[i].getTen()
        << setw(25) << dulieu[i].getTacGia()
        << setw(8)  << dulieu[i].getNam()
        << setw(20) << dulieu[i].getTheLoai()
        << setw(12) << fixed << setprecision(0) << dulieu[i].getGia()
        << setw(10) << dulieu[i].getSoLuong()
        << setw(15) << dulieu[i].getMaDonHang()
        << endl;
}
}
int Database::getSizedatabase() {
    return dulieu.size();
}
vector<Sach>& Database::getDulieu() {
    return dulieu;
}