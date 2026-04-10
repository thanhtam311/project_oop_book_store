#include"Data.h"
#include"Sach.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>   
#include <iomanip>
Data::Data(Database &db) : ds(db) {}
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
        }
        else if (line.find("Ma don hang:") != string::npos) {
            s.setMaDonHang(line.substr(line.find(":") + 2));
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
        fout << "Ma don hang: " << ds.getDulieu()[i].getMaDonHang() << endl;
        fout << "\n";
    }
    fout.close();
}