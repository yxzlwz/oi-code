#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a[10],aa=0;
    char in;
    char k;
    for(int i=0;i<12;i++){
        cin>>k;
        if(k!='-')a[++aa]=k-48;
    }
    cin>>in;
    long long t=0;
    aa=1;
    for(int i=1;i<=9;i++){
        t+=a[i]*i;
    }
    t%=11;
    if(t==10)t='X';
    else t+=48;
    if(t==in)cout<<"Right";
    else{
    	printf("%d-%d%d%d-%d%d%d%d%d-%c",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],t);
    }
    return 0;
}
