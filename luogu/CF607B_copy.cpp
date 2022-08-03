#include <bits/stdc++.h>
const int N = 550;
const int INF = 1e9;
using namespace std;
int n, dp[N][N], c[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < N; i++) dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) {
        if (c[i] == c[i + 1])
            dp[i][i + 1] = 1;
        else
            dp[i][i + 1] = 2;
    }
    for (int l = 2; l < n; l++) {
        for (int i = 0; i + l < n; i++) {
            int j = i + l;
            dp[i][j] = INF;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            if (c[i] == c[j]) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            }
        }
    }
    cout << dp[0][n - 1];
}