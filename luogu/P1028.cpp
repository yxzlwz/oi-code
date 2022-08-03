#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,count=0,ans[999],len=0;cin>>n;
    memset(ans,0,sizeof(ans));

    ans[len++]=n;
    //cout<<ans[0];
    int t[101],tt=0;
    int c=1;
    int cheng=100;
    for(int i=1;i<=n/2;i++){
        t[tt++]=i*cheng+n;
        for(int j=1;j<=i/2;j++){
            t[tt++]=j*cheng*10+t[tt-2];
        }
    }
    for(int i=0;i<tt;i++)ans[len++]=t[i];
    //cout<<len<<tt;
    for(int i=0;i<len;i++)cout<<ans[i]<<" ";
    cout<<endl;
    cout<<len<<endl;

    return 0;
}