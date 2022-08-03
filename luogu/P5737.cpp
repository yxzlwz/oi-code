#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

bool pd(int year){
    if((year%100 && year%4==0) || year%400==0)return true;
    return false;
}

int main(){
    int a,b;
    cin>>a>>b;
    int list[10000]={}, cnt=0;
    for(;a<=b;a++){
        if(pd(a)){
            list[cnt++]=a;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        cout<<list[i]<<" ";
    }

    return 0;
}