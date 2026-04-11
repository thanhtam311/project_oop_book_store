#include"doituong.h"
#include"Sach.h"
#include"Database.h"
#include"Data.h"
#include"hanhvi.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>   
#include <iomanip>
#include <cstdlib>
#include <ctime>
staff::staff(Database &d):HanhVi(d),Data(d),db(d){}
customer::customer(Database &d):HanhVi(d),Data(d),db(d){}
void staff::quanli()
{
    int chon;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Hien thi danh sach\n";
        cout << "2. Them sach\n";
        cout << "3. Tim sach theo ten\n";
        cout << "4. Tim sach theo the loai\n";
        cout << "5. Tim sach theo tac gia\n";
        cout << "6. Xoa sach\n";
        cout << "7. Sua gia\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;
        switch (chon) {
        case 1:
            db.database_show();
            break;
        case 2:
            themsach();
            break;
        case 3:
            timsachtheoten();
            break;
        case 4:
            timsachtheotheloai();
            break;
        case 5:
            timsachtheotacgia();
            break;
        case 6:
            xoasach();
            break;
        case 7:
            suagia();
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            xuatdata();
            break;
        default:
            cout << "Lua chon khong hop le! Vui long chon lai.\n";
        }
    } while (chon != 0);
}
void customer::thuchienmua()
{
    db.database_show();
    cout<<"Vui long nhap thong tin sach ban muon mua!\n";
    Mua();
    xuatdata();
}
doituong::doituong(Database &d) : staff(d),customer(d){}
void doituong::thuchien() 
{
    int chon;
    do{
        cout<<"Role cua ban la:\n";
        cout<<"1.Nguoi mua\n";
        cout<<"2.Quan li\n";
        cout<<"0.Thoat\n";
        cout<<"Moi ban chon Role: ";
        cin>>chon;
        switch (chon) {
        case 2:
            quanli();
            break;
        case 1:
            thuchienmua();
            break;
        case 0:
            cout<<"Cam on!";
            break;
        default:
            cout<<"xin cam on";
            break;
        }
    }while (chon!=0);
}