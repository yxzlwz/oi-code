#include <bits/stdc++.h>
using namespace std;

const int N = 15, mod = 100000000;

int m, n, dp[N][1 << N], mp[N];

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            mp[i] <<= 1;
            mp[i] += (!t);
        }
    }

    for (int i = 0; i < (1 << n); i++)
        if (!((i & (i << 1)) | (i & mp[0]))) dp[0][i] = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < (1 << n); ++j) {
            if (!((j & mp[i]) | (j & (j << 1)))) {
                for (int k = 0; k < (1 << n); k++) {
                    if (!(j & k)) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        ans = (ans + dp[m - 1][i]) % mod;
    }
    cout << ans;

    return 0;
}
