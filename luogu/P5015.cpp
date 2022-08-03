#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    char s[5];
    gets(s);
    int count=0,l=strlen(s);
    for(int i=0;i<l;i++)
        if(s[i]!=' ')count++;
    cout<<count;
}