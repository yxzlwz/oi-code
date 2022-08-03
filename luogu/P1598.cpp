#include<bits/stdc++.h>
using namespace std;
int main(){
    int count[26];
    memset(count,0,sizeof(count));
    for(int i=0;i<4;i++){
        char input[10001];
        gets(input);
        int len=strlen(input);
        for(int j=0;j<len;j++){
            if(input[j]>='A'&&input[j]<='Z'){
                count[input[j]-'A']++;
            }
        }
        //cout<<count[0];
    }
    int big=count[0];
    for(int i=0;i<25;i++){
        big=max(big,count[i+1]);
    }
    cout<<big;

    for(int i=0;i<big;i++){
        for(int j=0;j<26;j++){
            if(count[j]>=big-i)cout<<'*';
            else cout<<" ";
            if(j!=25)cout<<' ';
        }
        cout<<endl;
    }
    for(int i=0;i<25;i++)cout<<char('A'+i)<<" ";
    cout<<"Z";


    return 0;
}