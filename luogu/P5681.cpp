#include<iostream>
using namespace std;
int main(){
    long long a,b,c;cin>>a>>b>>c;
    long long m=a*a,n=b*c;
    if(m>n)cout<<"Alice";
    else cout<<"Bob";
}