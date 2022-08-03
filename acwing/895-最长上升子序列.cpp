#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int n, a[N], dp[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << *max_element(dp + 1, dp + n + 1) << endl;
}