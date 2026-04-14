#include"Data.h"
#include"Sach.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>   
#include <iomanip>
#include <cstdlib>
#include <ctime>
Data::Data(Database_Sach &db,Database_Donhang &x) : ds(db),dh(x) {}
void Data::Laydata(std::string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Vui long cung cap file chua danh sach sach\n";
        return;
    }
    string line;
    Sach s;
    while (getline(file, line)) {
        if (line.find("Ten sach:") != string::npos) {
            s.setTen(line.substr(line.find(":") + 2));
        }
        else if (line.find("Tac gia:") != string::npos) {
            s.setTacGia(line.substr(line.find(":") + 2));
        }
        else if (line.find("Nam xuat ban:") != string::npos) {
            s.setNam(stoi(line.substr(line.find(":") + 2)));
        }
        else if (line.find("The loai:") != string::npos) {
            s.setTheLoai(line.substr(line.find(":") + 2));
        }
        else if (line.find("Gia:") != string::npos) {
            s.setGia(stod(line.substr(line.find(":") + 2)));
        }
        else if (line.find("So luong:") != string::npos) {
            s.setSoLuong(stoi(line.substr(line.find(":") + 2)));
            ds.database_push(s);
            s = Sach();
        }
    }
    file.close();
}
void Data::xuatdata(){
    remove("danh_sach_sach.txt");
    ofstream fout("danh_sach_sach.txt");
    for(int i = 0; i < ds.getSizedatabase(); i++){
        fout << "Ten sach: " << ds.getDulieu()[i].getTen() << endl;
        fout << "Tac gia: " << ds.getDulieu()[i].getTacGia() << endl;
        fout << "Nam xuat ban: " << ds.getDulieu()[i].getNam() << endl;
        fout << "The loai: " << ds.getDulieu()[i].getTheLoai() << endl;
        fout << "Gia: " << ds.getDulieu()[i].getGia() << endl;
        fout << "So luong: " << ds.getDulieu()[i].getSoLuong() << endl;
        fout << "\n";
    }
    fout.close();
}
void Data::xuathoadon(){
    remove("luutru.txt");
    ofstream fiout("luutru.txt");
    for(int i = 0; i < dh.getSizedatabase(); i++){
        if(dh.getDulieu()[i].check == true){
            fiout << "===== HOA DON MUA =====\n";
            fiout << "Ma hoa don: "<<dh.getDulieu()[i].id_donhang<<endl;
            fiout << "Ten sach: " <<dh.getDulieu()[i].ten<< endl;
            fiout << "So luong: " << dh.getDulieu()[i].soluong << endl;
            fiout << "Don gia:  " << fixed << setprecision(0) << dh.getDulieu()[i].dongia  << endl;
            fiout << "Thoi gian: " << dh.getDulieu()[i].tg.ngay << "/" << dh.getDulieu()[i].tg.thang << "/" << dh.getDulieu()[i].tg.nam << " " << dh.getDulieu()[i].tg.gio << ":" << dh.getDulieu()[i].tg.phut << ":" << dh.getDulieu()[i].tg.giay << endl;
            fiout << "------------------------\n";
            fiout << "TONG TIEN: " << fixed << setprecision(0) << dh.getDulieu()[i].tien<< " VND\n";
        }else 
        {
            fiout << "===== HOA DON THUE =====\n";
            fiout << "Ma hoa don: "<<dh.getDulieu()[i].id_donhang<<endl;
            fiout << "Ten sach: " << dh.getDulieu()[i].ten << endl;
            fiout << "So luong: " << dh.getDulieu()[i].soluong << endl;
            fiout << "Don gia thue:  " << fixed << setprecision(0) << dh.getDulieu()[i].dongia << endl;
            fiout << "Thoi gian: " << dh.getDulieu()[i].tg.ngay << "/" << dh.getDulieu()[i].tg.thang << "/" << dh.getDulieu()[i].tg.nam << " " << dh.getDulieu()[i].tg.gio << ":" << dh.getDulieu()[i].tg.phut << ":" << dh.getDulieu()[i].tg.giay << endl;
            fiout << "------------------------\n";
            fiout << "TONG TIEN: " << fixed << setprecision(0) << dh.getDulieu()[i].tien << " VND\n";
        }
    }
    fiout.close();
}