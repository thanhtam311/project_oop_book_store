#include"hanhvi.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>   
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
HanhVi::HanhVi(Database_Sach &d, Database_Donhang &c) : dbs(d),dbd(c) {}
void HanhVi::Mua() {
    string tensach;
    bool timthay = false;
    cin.ignore();
    cout << "Nhap ten sach muon mua: ";
    getline(cin, tensach);
    vector<Sach>& danhsach = dbs.getDulieu();
    mahanghoa hoadon;
    hoadon.check = true;
    for (int i = 0; i < (int)danhsach.size(); i++) {
        if (danhsach[i].getTen() == tensach) {
            timthay = true;
            cout << "Thong tin sach: " << danhsach[i].getTen() << endl;
            cout << "Gia: " << fixed << setprecision(0) << danhsach[i].getGia() << " | Ton kho: " << danhsach[i].getSoLuong() << endl;
            if (danhsach[i].getSoLuong() <= 0) {
                cout << "Xin loi, sach nay hien da het hang!\n";
                return;
            }
            cout << "Nhap so luong muon mua: ";
            cin >> hoadon.soluong;
            if (hoadon.soluong <= 0) {
                cout << "So luong mua khong hop le!\n";
            }
            else if (hoadon.soluong > danhsach[i].getSoLuong()) {
                cout << "Khong du so luong trong kho! (Chi con " << danhsach[i].getSoLuong() << " cuon)\n";
            }
            else {
                danhsach[i].setSoLuong(danhsach[i].getSoLuong() - hoadon.soluong);
                dbs.database_show();
                srand(time(0));
                hoadon.id_donhang=1000 + rand() % 9000;
                hoadon.tien = hoadon.soluong * danhsach[i].getGia(); 
                hoadon.ten = danhsach[i].getTen();
                hoadon.dongia = danhsach[i].getGia();
                hoadon.tg = layThoigianHienTai();
                cout<<"Hoa don da duoc xuat vui long kiem tra thong tin!\n";                   
                remove("hoa_don.txt");
                ofstream fiout("hoa_don.txt");
                fiout << "===== HOA DON XUAT =====\n";
                fiout << "Ma hoa don: "<<hoadon.id_donhang<<endl;
                fiout << "Ten sach: " << hoadon.ten<< endl;
                fiout << "So luong: " << hoadon.soluong << endl;
                fiout << "Don gia:  " << fixed << setprecision(0) << hoadon.dongia  << endl;
                fiout << "Thoi gian: " << hoadon.tg.ngay << "/" << hoadon.tg.thang << "/" << hoadon.tg.nam << " " << hoadon.tg.gio << ":" << hoadon.tg.phut << ":" << hoadon.tg.giay << endl;
                fiout << "------------------------\n";
                fiout << "TONG TIEN: " << fixed << setprecision(0) << hoadon.tien << " VND\n";
                fiout << "Giao dich thanh cong! So luong ton kho da duoc cap nhat.\n";
                dbd.database_push(hoadon);
                dbd.database_show();
                fiout.close();
            }
            break;
        }
    }
    if (!timthay) {
        cout << "Khong tim thay sach co ten nay trong he thong!" << endl;
    }
}
void HanhVi::themsach() {
    Sach s;
    cout << "Nhap thong tin sach moi:\n";
    cin.ignore();
    s.input();
    vector<Sach>& ds = dbs.getDulieu();
    for (int i = 0; i < (int)ds.size(); i++) {
        if (ds[i].getTen() == s.getTen() && ds[i].getTacGia() == s.getTacGia()) {
            int sl = ds[i].getSoLuong() + s.getSoLuong();
            ds[i].setSoLuong(sl);
            cout << "Sach da duoc them\n";
            return;
        }
    }
    dbs.database_push(s);
    cout << "Da them sach moi!\n";
}
void HanhVi::timsachtheoten() {
    string tensach;
    bool timthay = false;
    cin.ignore();
    cout << "Nhap ten sach can tim: ";
    getline(cin, tensach);
    vector<Sach>& danhsach = dbs.getDulieu();
    for (int i = 0;i < (int)danhsach.size();i++) {
        if (danhsach[i].getTen() == tensach) {
            cout << "Tim thay sach: ";
            cout << "Ten: " << danhsach[i].getTen() << endl;
            cout << "Tac gia: " << danhsach[i].getTacGia() << endl;
            cout << "Nam: " << danhsach[i].getNam() << endl;
            cout << "So luong: " << danhsach[i].getSoLuong() << endl;
            cout << "The loai: " << danhsach[i].getTheLoai() << endl;
            cout << "Gia: " << fixed << setprecision(0) << danhsach[i].getGia() << endl;
            timthay = true;
        }
    }
    if (!timthay) {
        cout << "Khong tim thay sach!" << endl;
    }
}
void HanhVi::timsachtheotheloai() {
    string theloai;
    bool timthay = false;
    cin.ignore();
    cout << "Nhap the loai can tim: ";
    getline(cin, theloai);
    vector<Sach>& danhsach = dbs.getDulieu();
    for (int i = 0;i < (int)danhsach.size();i++) {
        if (danhsach[i].getTheLoai() == theloai) {
            cout << "Tim thay sach: ";
            cout << "Ten: " << danhsach[i].getTen() << endl;
            cout << "Tac gia: " << danhsach[i].getTacGia() << endl;
            cout << "Nam: " << danhsach[i].getNam() << endl;
            cout << "So luong: " << danhsach[i].getSoLuong() << endl;
            cout << "The loai: " << danhsach[i].getTheLoai() << endl;
            cout << "Gia: " << fixed << setprecision(0) << danhsach[i].getGia() << endl;
            timthay = true;
        }
    }
    if (!timthay) {
        cout << "Khong tim thay sach!" << endl;
    }
}
void HanhVi::timsachtheotacgia() {
    string tacgia;
    bool timthay = false;
    cin.ignore();
    cout << "Nhap tac gia can tim: ";
    getline(cin, tacgia);
    vector<Sach>& danhsach = dbs.getDulieu();
    for (int i = 0;i < (int)danhsach.size();i++) {
        if (danhsach[i].getTacGia() == tacgia) {
            cout << "Tim thay sach: ";
            cout << "Ten: " << danhsach[i].getTen() << endl;
            cout << "Tac gia: " << danhsach[i].getTacGia() << endl;
            cout << "Nam: " << danhsach[i].getNam() << endl;
            cout << "So luong: " << danhsach[i].getSoLuong() << endl;
            cout << "The loai: " << danhsach[i].getTheLoai() << endl;
            cout << "Gia: " << fixed << setprecision(0) << danhsach[i].getGia() << endl;
            timthay = true;
        }
    }
    if (!timthay) {
        cout << "Khong tim thay sach!" << endl;
    }
}
void HanhVi::xoasach() {
    string tensach;
    bool timthay = false;
    cin.ignore();
    cout << "Nhap ten sach can xoa: ";
    getline(cin, tensach);
    vector<Sach>& danhsach = dbs.getDulieu();
    for (int i = 0;i < (int)danhsach.size();i++) {
        if (danhsach[i].getTen() == tensach) {
            danhsach.erase(danhsach.begin() + i);
            cout << "Da xoa sach!\n";
            timthay = true;
            break;
        }
    }
    if (!timthay) {
        cout << "Khong tim thay sach!" << endl;
    }
}
void HanhVi::suagia() {
    string tensach;
    bool timthay = false;
    cin.ignore();
    cout << "Nhap ten sach can sua gia: ";
    getline(cin, tensach);
    vector<Sach>& danhsach = dbs.getDulieu();
    for (int i = 0;i < (int)danhsach.size();i++) {
        if (danhsach[i].getTen() == tensach) {
            double giagoc = danhsach[i].getGia();
            double giamoi;
            cout << "Gia cu: " << fixed << setprecision(0) << giagoc << endl;
            cout << "Nhap gia moi: ";
            cin >> giamoi;
            danhsach[i].setGia(giamoi);
            cout << "Da cap nhat!\n";
            timthay = true;
            break;
        }
    }
    if (!timthay) {
        cout << "Khong tim thay sach!" << endl;
    }
}
thoigian HanhVi::layThoigianHienTai(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    thoigian tg;
    tg.ngay = ltm->tm_mday;
    tg.thang = 1 + ltm->tm_mon;
    tg.nam = 1900 + ltm->tm_year;
    tg.gio = ltm->tm_hour;
    tg.phut = ltm->tm_min;
    tg.giay = ltm->tm_sec;
    return tg;
}
void HanhVi::thuesach() {
    string tensach;
    string tenkhach;
    bool timthay = false;
    cin.ignore();
    cout << "Nhap ten sach can thue: ";
    getline(cin, tensach);
    vector<Sach>& danhsach = dbs.getDulieu();
    mahanghoa hoadon;
    hoadon.check = false;
    for (int i = 0;i < (int)danhsach.size();i++) {
        if (danhsach[i].getTen() == tensach) {
            timthay = true;
            cout << "Thong tin sach: " << danhsach[i].getTen() << endl;
            cout << "Gia thue: " << fixed << setprecision(0) << danhsach[i].getGia() * 0.1 << " | Ton kho: " << danhsach[i].getSoLuong() << endl;
            if (danhsach[i].getSoLuong() <= 0) {
                cout << "Xin loi, sach nay hien da het hang!\n";
                return;
            }
            cout << "Nhap so luong muon thue: ";
            cin >> hoadon.soluong;
            cout << "nhap thoi gian thue (so ngay): ";
            int songay;
            cin >> songay;
            if (hoadon.soluong <= 0) {
                cout << "So luong thue khong hop le!\n";
            }
            else if (hoadon.soluong > danhsach[i].getSoLuong()) {
                cout << "Khong du so luong trong kho! (Chi con " << danhsach[i].getSoLuong() << " cuon)\n";
            }
            else {
                danhsach[i].setSoLuong(danhsach[i].getSoLuong() - hoadon.soluong);
                dbs.database_show();
                srand(time(0));
                hoadon.id_donhang = 1000 + rand() % 9000;
                hoadon.ten = danhsach[i].getTen();
                hoadon.dongia = danhsach[i].getGia() * 0.1;
                hoadon.tg = layThoigianHienTai();
                hoadon.tien = hoadon.soluong * hoadon.dongia* songay;
                cout<<"Hoa don da duoc xuat vui long kiem tra thong tin!\n";                   
                remove("hoa_don_thue.txt");
                ofstream fiout("hoa_don_thue.txt");
                fiout << "===== HOA DON THUE =====\n";
                fiout << "Ma hoa don: "<<hoadon.id_donhang<<endl;
                fiout << "Ten sach: " << hoadon.ten << endl;
                fiout << "So luong: " << hoadon.soluong << endl;
                fiout << "Don gia thue:  " << fixed << setprecision(0) << hoadon.dongia << endl;
                fiout << "Thoi gian: " << hoadon.tg.ngay << "/" << hoadon.tg.thang << "/" << hoadon.tg.nam << " " << hoadon.tg.gio << ":" << hoadon.tg.phut << ":" << hoadon.tg.giay << endl;
                fiout << "------------------------\n";
                fiout << "TONG TIEN: " << fixed << setprecision(0) << hoadon.tien << " VND\n";
                fiout.close();
                dbd.database_push(hoadon);
            }
            break;
        }
    }
    if (!timthay) {
        cout << "Khong tim thay sach!" << endl;
    }

}
void HanhVi::trasach(){
    int id_donhang;
    bool timthay = false;
    cout << "Nhap ma hoa don thue can tra: ";
    cin >> id_donhang;
    vector<mahanghoa>& danhsach = dbd.getDulieu();
    for (int i = 0;i < (int)danhsach.size();i++) {
        if (danhsach[i].id_donhang == id_donhang && danhsach[i].check == false) {
            thoigian tgtra = layThoigianHienTai();
            int songaythue = (tgtra.nam - danhsach[i].tg.nam) * 365 + (tgtra.thang - danhsach[i].tg.thang) * 30 + (tgtra.ngay - danhsach[i].tg.ngay);
            if(danhsach[i].soluong * danhsach[i].dongia * songaythue > danhsach[i].tien){
                cout << "Khach hang da thue qua han! Vui long tra sach va thanh toan tien phat!\n";
                danhsach[i].tien = danhsach[i].soluong * danhsach[i].dongia * songaythue;
            }
            timthay = true;
            vector<Sach>& danhsach_sach = dbs.getDulieu();
            for (int j = 0; j < (int)danhsach_sach.size(); j++) {
                if (danhsach_sach[j].getTen() == danhsach[i].ten) {
                    danhsach_sach[j].setSoLuong(danhsach_sach[j].getSoLuong() + danhsach[i].soluong);
                    cout << "Da cap nhat so luong ton kho!\n";
                    break;
                }
            }
            break;
        }
    }
    if (!timthay) {
        cout << "Khong tim thay hoa don thue!" << endl;
    }

}