#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n, m, a[N][N], dp[N][N];

int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    int ans = 1;
    if (x + 1 <= n && a[x][y] > a[x + 1][y]) ans = max(ans, 1 + dfs(x + 1, y));
    if (y + 1 <= m && a[x][y] > a[x][y + 1]) ans = max(ans, 1 + dfs(x, y + 1));
    if (x - 1 >= 1 && a[x][y] > a[x - 1][y]) ans = max(ans, 1 + dfs(x - 1, y));
    if (y - 1 >= 1 && a[x][y] > a[x][y - 1]) ans = max(ans, 1 + dfs(x, y - 1));
    return dp[x][y] = ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] == -1) {
                ans = max(ans, dfs(i, j));
            }
        }
    }
    cout << ans << endl;
    return 0;
}