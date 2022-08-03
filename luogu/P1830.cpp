#include<cstdio>
#include<iostream>
using namespace std;

struct data
{
    char yn;
    int times,last;
}a[101][101];


int main(){
    int n,m,x,y;cin>>n>>m>>x>>y;
    int pd1=x;
    while(pd1--){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                a[i][j].yn='Y';a[i][j].times++;a[i][j].last=x-pd1;
            }
        }
    }

    int xx[101],yy[101];
    for(int i=1;i<=y;i++)cin>>xx[i]>>yy[i];

    int pd2=0;
    while(pd2++<=y){
        if(a[xx[pd2]][yy[pd2]].yn!='Y')cout<<'N'<<endl;
        else cout<<"Y "<<a[xx[pd2]][yy[pd2]].times<<' '<<a[xx[pd2]][yy[pd2]].last<<endl;
    }

    return 0;
}