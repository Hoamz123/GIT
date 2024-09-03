#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*ll ucln(ll a,ll b){
    while(b != 0){
        ll tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

class phanso{
    private:
        ll tu,mau;
    public:
        void nhap();
        void in();
        friend void rutgon(phanso &a);
};
void phanso::nhap(){
    cout<<"Nhap tu: ";cin>>tu;
    cout<<"Nhap mau: ";cin>>mau;
}
void rutgon(phanso &a){
    ll UCLN = ucln(a.tu,a.mau);
    a.tu/=UCLN;
    a.mau/=UCLN;
}

void phanso :: in(){
    cout<<tu<<"/"<<mau<<endl;
}
int main(){
    phanso a;
    a.nhap();
    rutgon(a);
    a.in();
    return 0;
}*/

/*ll ucln(ll a, ll b)
{
    while (b != 0)
    {
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
class phanso{
    private:
    ll tu,mau;
    public:
    phanso();//constructor
    //nap chong toans tu
    friend istream& operator >> (istream& in,phanso&);//truyen tham chieu
    friend ostream& operator << (ostream& out,phanso);
    void rutgon();
    friend phanso tong(phanso a,phanso b);//ham ban tra ve kieu phanso
};

phanso :: phanso(){
    tu = 0;mau = 0;
}

ostream& operator << (ostream& out,phanso a){
    out<<a.tu<<"/" <<a.mau;
    return out;
}
istream& operator >> (istream& in,phanso &a){
    in>>a.tu>>a.mau;
    return in;
}
void phanso :: rutgon(){
    ll UCLN = ucln(tu,mau);
    tu/=UCLN;
    mau/=UCLN;
}
phanso tong(phanso a,phanso b){
    phanso c;
    c.tu = a.tu * b.mau + a.mau * b.tu;
    c.mau = a.mau * b.mau;
    c.rutgon();
    return c;
}
int main(){
    phanso x,y;
    cin>>x>>y;
    x.rutgon();
    y.rutgon();
    phanso z = tong(x,y);
    cout<<z<<endl;
    return 0;
}*/

/*ll ucln(ll a, ll b)
{
    while (b != 0)
    {
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
ll bcnn(ll a,ll b){
    return  (a*b) / ucln(a,b);
}
class phanso{
    private:
    ll tu,mau;
    public:
    phanso(ll,ll);

    //nap chong toan tu
    void rutgon();
    friend istream& operator >> (istream& in,phanso&);
    friend ostream& operator << (ostream& out,phanso);
    friend phanso operator + (phanso,phanso);
};
istream &operator >> (istream &in, phanso &a){
    cin>>a.tu>>a.mau;
    return in;
}
ostream &operator << (ostream &out,phanso a){
    cout<<a.tu<<"/" <<a.mau;
    return out;
}
phanso::phanso(ll tu, ll mau){
    this->tu = tu;
    this->mau = mau;
}
void phanso :: rutgon(){
    ll UCLN = ucln(tu,mau);
    tu/=UCLN;
    mau/=UCLN;
}
phanso operator + (phanso a,phanso b){
    phanso tong(1,1);//khai bai mot phan so tong
    ll mc = bcnn(a.mau,b.mau);
    tong.tu = (mc/a.mau) * a.tu + (mc/b.mau) * b.tu;
    tong.mau = mc;
    tong.rutgon();
    return tong;
}
int main(){
    phanso p(1,1),q(1,1);
    cin>>p>>q;
    cout<<q+p<<endl;
    return 0;
}*/

class sinhvien{
    private:
        string name,id,lop,date;
        float gpa;
        static int dem;
    public:
        sinhvien();//constructor
        //nap chong toan tu
        friend istream& operator >> (istream& in, sinhvien&);
        friend ostream& operator << (ostream& out,sinhvien);
        void tangdem(){
            dem++;
        }
        int getdem(){
            return dem;
        } 
        friend void chuanhoa(sinhvien &a);//truyen tham chieu
};
int sinhvien :: dem = 0;
sinhvien::sinhvien(){
    id = name = lop = date = "";
    gpa = 0;
}

istream& operator >> (istream& in , sinhvien &a){
    a.tangdem();
    int dm = a.getdem();
    cout<<"Nhap ten: ";getline(in,a.name);
    cout<<"Nhap lop: ";in>>a.lop;
    a.id = "B20DCCN" + string(3 - to_string(dm).length(),'0');a.id += (dm + '0');
    cout<<"Nhap date: ";in>>a.date;
    cout<<"Nhap Gpa: ";in>>a.gpa;
    cin.ignore();
    return in;
}

ostream& operator << (ostream& out,sinhvien a){
    out<<a.id<<" "<<a.name<<" "<<a.lop<<" "<<a.date<<" "<<fixed<<setprecision(2)<<a.gpa<<endl;
    return out;
}

void chuanhoa(sinhvien &a){
    //dang dd//mm/yy
    if(a.date[2] != '/'){
        a.date = "0" + a.date;
    }
    if(a.date[5] != '/'){
        a.date.insert(3,"0");//chen them so 0 o vi tri co chi so 3
    }
}
int main(){
    sinhvien a;
    cin>>a;
    chuanhoa(a);
    cout<<a<<endl;
    return 0;
}