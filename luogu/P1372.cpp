#include<bits/stdc++.h>
using namespace std;

long long a[100000000][100000000];

int main(){
    long long n,k,max=0;cin>>n>>k;
    long long a[n+1];
    //for(long long i=0;i<=n+1;i++)a[i]=i;

    for(long long i=1;i<=k;i++)
        for(long long j=1;j<=n;j++)a[i][j]=j;

    //b[]

    return 0;
}