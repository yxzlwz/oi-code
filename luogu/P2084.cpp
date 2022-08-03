#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
    int a;cin>>a;
    string s;cin>>s;
    int l=s.length()-1;
    //cout<<endl<<s;
    for(int i=l;i>0;i--)cout<<s[l-i]<<"*"<<a<<"^"<<i<<"+";
    cout<<s[l]<<"*"<<a<<"^"<<0<<endl;

    return 0;
}