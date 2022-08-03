#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;cin>>n>>m;
    long long w[n];
    for(long long i=0;i<n;i++)cin>>w[i];
    sort(w,w+n);
    long long r[m];
    memset(r,0,sizeof(r));
    long long t=0,p=0;
    for(long long i=0;i<m;i++){
        r[i]+=w[i];
        p++;
    }
    //cout<<endl;
    while(1){
        t++;
        for(long long i=0;i<m;i++){
            if(r[i]==t){
                r[i]+=w[p++];
            }
        }
        if(p==n){
            t+=w[n-1];
            break;
        }
    }
    cout<<t-1;

    return 0;
}