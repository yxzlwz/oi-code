#include<iostream>
using namespace std;
int main(){
    char a[8];short count=0;
    for(int i=0;i<8;i++){
        cin>>a[i];
        if(a[i]=='1')count++;
    }
    cout<<count;
}