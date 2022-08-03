#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[N], dp[N], last_max[N], last_min[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++){
        // 计算出last_max和last_min，同时计算出dp数组
        last_max[i] = i - 1;
        if(a[i] >= a[i - 1])last_max[i] = last_max[i - 1];
        last_min[i] = i - 1;
        if(a[i] <= a[i - 1])last_min[i] = last_min[i - 1];

        dp[i] = min(dp[last_min[i]], dp[last_max[i]]) + 1;
    }
    cout << dp[n];

    return 0;
}