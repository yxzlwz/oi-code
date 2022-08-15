#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int a, b, num[N], dp[N][N];

int dfs(int pos, int pre, bool qd0, bool lim) {
    if (pos == -1) return 1;
    if (!lim && !qd0 && dp[pos][pre] != -1) return dp[pos][pre];
    int up = lim ? num[pos] : 9, s = 0;
    for (int i = 0; i <= up; i++) {
        if (abs(i - pre) < 2 && !qd0) continue;
        s += dfs(pos - 1, i, qd0 && i == 0, lim && i == up);
    }
    if (!lim && !qd0) dp[pos][pre] = s;
    return s;
}

int solve(int x) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) dp[i][j] = -1;
    int len = 0;
    while (x) {
        num[len++] = x % 10;
        x /= 10;
    }
    return dfs(len - 1, 0, true, true);
}

int main() {
    cin >> a >> b;

    cout << solve(b) - solve(a - 1) << endl;

    return 0;
}
