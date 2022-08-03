#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    int a[100001];
    cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> a[i];
    int l = 0, r = 1000000;
    while(l <= r){
        int mid = (l + r) / 2, cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += max(a[i] - mid, 0);
        }
        if(cnt > m)l = mid + 1;
        else r = mid - 1;
    }
    cout<<l;
    return 0;
}