#include <bits/stdc++.h>
using namespace std;

const int N = 101, M = 11;

int n, m, dp[3][1 << M][1 << M], mp[N], gcnt[1 << M];

inline int bitcnt(int x) {
    if (gcnt[x]) return gcnt[x];
    int cnt = 0, xx = x;
    while (x) {
        x &= x - 1;
        cnt++;
    }
    return gcnt[xx] = cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char t;
            cin >> t;
            mp[i] <<= 1;
            mp[i] += (t == 'H');
        }
    }

    for (int i = 0; i < (1 << m); i++)
        if (!((i & (i << 1)) | (i & (i << 2)) | (i & mp[0])))
            dp[0][0][i] = bitcnt(i);

    if (n == 1) {
        int ans = 0;
        for (int i = 0; i < (1 << m); ++i) ans = max(ans, dp[0][0][i]);
        cout << ans;
        return 0;
    }

    for (int i = 0; i < (1 << m); i++)
        for (int j = 0; j < (1 << m); j++)
            if (!((i & (i << 1)) | (i & (i << 2)) | (i & j) | (j & (j << 1)) |
                  (j & (j << 2)) | (j & mp[1])))
                dp[1][i][j] = max(dp[1][i][j], dp[0][0][i] + bitcnt(j));

    for (int i = 2; i < n; i++) {
        for (int j = 0; j < (1 << m); j++) {  // 当前行
            if (((j & (j << 1)) | (j & (j << 2)) | (j & mp[i]))) continue;
            for (int k = 0; k < (1 << m); k++) {  // 前一行
                if (((k & (k << 1)) | (k & (k << 2)) | (k & j) |
                     (k & mp[i - 1])))
                    continue;
                for (int l = 0; l < (1 << m); l++) {  // 前两行
                    if (((l & (l << 1)) | (l & (l << 2)) | (l & j) | (l & k) |
                         (l & mp[i - 2])))
                        continue;
                    dp[i % 3][k][j] =
                        max(dp[i % 3][k][j], dp[(i - 1) % 3][l][k] + bitcnt(j));
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << m); i++)
        for (int j = 0; j < (1 << m); j++)
            ans = max(ans, dp[(n - 1) % 3][i][j]);
    cout << ans;

    return 0;
}
