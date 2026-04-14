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
staff::staff(Database_Sach &d,Database_Donhang &x):HanhVi(d,x),Data(d,x),db(d),dh(x){}
customer::customer(Database_Sach &d,Database_Donhang &x):HanhVi(d,x),Data(d,x),db(d),dh(x){}
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
    xuathoadon();
}
void customer::thuchienthue()
{
    db.database_show();
    cout<<"Vui long nhap thong tin sach ban muon thue!\n";
    thuesach();
    xuatdata();
    xuathoadon();
}
void customer::thuchientra()
{
    trasach();
    xuathoadon();
    xuatdata();
}
doituong::doituong(Database_Sach &d,Database_Donhang &x) : staff(d,x),customer(d,x){}
void doituong::thuchien() 
{
    int chon;
    do{
        cout<<"Role cua ban la:\n";
        cout<<"1.Nguoi mua\n";
        cout<<"2.Quan li\n";
        cout<<"3.Nguoi thue sach\n";
        cout<<"4.Khach hang tra sach\n";
        cout<<"0.Thoat\n";
        cout<<"Moi ban chon Role: ";
        cin>>chon;
        switch (chon) {
        case 4:
            thuchientra();
            break;
        case 3:
            thuchienthue();
            break;
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