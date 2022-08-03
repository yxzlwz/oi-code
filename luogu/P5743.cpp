#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, ans=1;
    cin>>n;
    while(--n){
        ans = (ans + 1) * 2;
    }
    cout<<ans;
    return 0;
}