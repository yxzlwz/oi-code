#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int a[5000][5000];
int main(){
    memset(a,false,sizeof(a));
    int n,m,b,g;cin>>n>>m>>b>>g;
    for(int i=0;i<b;i++){
        int x,y;cin>>x>>y;
        for(int j=x;j<=y;j++){
            for(int k=0;k<m;k++)a[j][k]=1;
        }
    }
    for(int i=0;i<g;i++){
        int x,y;cin>>x>>y;
        for(int j=x;j<=y;j++){
            for(int k=0;k<n;k++)a[k][j]=1;
        }
    }

    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j])count++;
        }
    }

    cout<<count;

    return 0;
}
