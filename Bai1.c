#include<stdio.h>
#include<math.h>
struct ps{
    int tu;
    int mau;
};
typedef struct ps ps;
//ham tinh uoc chung lon nhat
int UCLN(int a,int b){
    a = abs(a);
    b = abs(b);
    while(b!=0){
        int tmp = b;
        b =a%b;
        a = tmp;
    }
    return a;
}
//ham rut gon
void rutGon(int tu,int mau){
    if(tu > mau){
        printf("%d,%d/%d\n",tu / mau,(tu % mau),mau);
    }
    else{
        printf("%d/%d\n",tu,mau);
    }
}
int main(){
    //khai bao hai phan so
    ps a,b;
    //nhap tu va mau
    scanf("%d %d",&a.tu,&a.mau);
    scanf("%d %d", &b.tu, &b.mau);
    //tong
    {
        if(a.mau != 0 && b.mau != 0){
            int tu = a.tu * b.mau + b.tu * a.mau;
            int mau = a.mau * b.mau;
            //rut gon
            int UC = UCLN(tu,mau);
            int T = tu / UC;
            int M = mau / UC;
            
            rutGon(T,M);
        }
    }
    //hieu
    {
        if(a.mau != 0 && b.mau != 0){
            int tu = a.tu * b.mau - a.mau * b.tu;
            int mau = a.mau * b.mau;
            //rut gon
            int UC = UCLN(tu, mau);
            int T = tu / UC;
            int M = mau / UC;

            rutGon(T, M);
        }
    }
    //tich
    {
        if(a.mau != 0 && b.mau != 0){
            int tu = a.tu * b.tu;
        int mau = a.mau * b.mau;
        //rut gon
        int UC = UCLN(tu, mau);
        int T = tu / UC;
        int M = mau / UC;

        rutGon(T, M);
        }
    }
    //thuong
    {
        if(a.mau != 0 && b.mau != 0 && b.tu != 0){
            int tu = a.tu * b.mau;
            int mau = a.mau * b.tu;
            //rut gon
            int UC = UCLN(tu, mau);
            int T = tu / UC;
            int M = mau / UC;

            rutGon(T, M);
        }
    }
    //hoamz
    //da sua ngay 9/4
    
    return 0;
}
