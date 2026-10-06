#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class THEBAOHIEM
{
    protected:
    int MST;
    string TEN;
    string ngayphathanh;
    double mucphidong;
    public:
    virtual ~ THEBAOHIEM() {};
    virtual void nhap();
    virtual void xuat();
    virtual int  getloai() = 0;
    virtual double mucboithuong() = 0;
    virtual double mucphicoban() = 0;
    virtual int so_ngaymax() = 0;
};

void THEBAOHIEM :: nhap()
{
    cout<<"\nnhap ma the: "; cin>>MST;
    cout<<"\nten chu the: ";
    cin.ignore();
    getline(cin, TEN);
    cout<<"\nngay phat hanh: ";
    getline(cin,ngayphathanh);
    cout<<"\nmuc phi dong: "; cin>>mucphidong;
}

void THEBAOHIEM :: xuat()
{
    cout<<"\nnhap ma the: "<<MST;
    cout<<"\nten chu the: "<<TEN;
    cout<<"\nngay phat hanh: "<<ngayphathanh;
    cout<<"\nmuc phi dong: "<<mucphidong;
}

class THENOITRU : public THEBAOHIEM
{
    int so_ngay_max;
    public:
    void nhap() override;
    void xuat( )override;
    double mucboithuong() override;
    double mucphicoban() override
    {
        return mucphidong;
    }
    int getloai(){
        return 1;
    };
    int so_ngaymax() override
    {
        return so_ngay_max;
    }
};

void THENOITRU :: nhap()
{
    THEBAOHIEM ::nhap();
    cout<<"\nso ngay nam vien toi da: ";
    cin>>so_ngay_max;
}

void THENOITRU :: xuat()
{
    THEBAOHIEM ::xuat();
    cout<<"\nso ngay nam vien toi da: "<<so_ngay_max;
}

double  THENOITRU :: mucboithuong()
{
    return (mucphidong*10 + so_ngay_max*200000);
}


class THENGOAITRU : public THEBAOHIEM
{
    double uu_dai;
    public:
    void nhap() override;
    void xuat( )override;
    int so_ngaymax() override { return 0; }
    double mucboithuong() override;
     double mucphicoban() override
    {
        return mucphidong;
    }
    int getloai(){
        return 2;
    };
};

void THENGOAITRU :: nhap()
{
    THEBAOHIEM ::nhap();
    cout<<"\nty le uu dai kham benh: ";
    cin>>uu_dai;
}

void THENGOAITRU :: xuat()
{
    THEBAOHIEM ::xuat();
    cout<<"\nty le uu dai kham benh: "<<uu_dai;
}

double THENGOAITRU :: mucboithuong()
{
    return (mucphidong*5*(1 + uu_dai));
}

int main()
{
    int n, loaibh;
    cin>>n;
    THEBAOHIEM* ds[1000];

    //cau 1:
    for (int i=0; i<n; i++)
    {
        cout<<"\nchon loai bao hiem bao ";
        cout<<"\nhiem noi tru: 1; bao hiem ngoai tru: 2"<<endl;
        cin>>loaibh;
        if (loaibh == 1)
            ds[i] = new THENOITRU;
        else if (loaibh == 2) ds[i] = new THENGOAITRU;
        ds[i]->nhap();
    }

    //cau 2:
    for (int i=0; i<n; i++)
    {
        ds[i]->xuat();
        cout<<"\nmuc boi thuong toi da: ";
        
        cout<<fixed<<setprecision(3)<<ds[i]->mucboithuong();
    }

    //cau 3:
    double s = 0;
    for (int i=0; i<n; i++)
    {
        s += ds[i]->mucboithuong();
    }
    cout<<"\ntong tien du phong toi da cua tat ca khach hang: ";
    
    cout<<fixed<<setprecision(3)<<s;

    //cau 4:
    double m = 0;
    for (int i=0; i<n; i++)
    {
        m += ds[i]->mucphicoban();
    }
    m = m/n;
    cout<<"\ntrung binh muc phi dong cua toan bo khach hang: "<<m;

    //cau 5:
    bool f = false;
    for (int i=0; i<n; i++)
    {
        if (ds[i]->getloai() == 2)
            {
                if (ds[i]->mucphicoban() < m) {ds[i]->xuat(); f=true;}
            }
    }
    if (!f) cout<<"\nkhong co the ngoai tru nao co muc phi dong thap hon muc trung binh";

    //cau 6:
    int min = 9999999;
    for (int i=0; i<n; i++)
    {
        if (ds[i]->getloai() == 1)
            {
                if (ds[i]->so_ngaymax() < min)  min  = ds[i]->so_ngaymax();
            }
    }

    if (min == 9999999) cout<<"\nkhong co khach hang dang ky noi tru";
    else
    {
        for (int i=0; i<n; i++)
            if (ds[i]->getloai() == 1)
                if (ds[i]->so_ngaymax() == min ) {ds[i]->xuat(); break;}

    }

    for (int i=0; i<n; i++)
        delete ds[i];

    return 0;
}

