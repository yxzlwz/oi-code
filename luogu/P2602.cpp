#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int a, b, num[N], dp[N][N], cnt[N], cur;

int dfs(int pos, int pre, bool qd0, bool lim, int cntt) {
    if (pos == -1) return 1;
    // if (!lim && !qd0 && dp[pos][cntt] != -1) return dp[pos][pre];
    int up = lim ? num[pos] : 9, s = 0;
    for (int i = 0; i <= up; i++) {
        if (abs(i - pre) < 2 && !qd0) continue;
        s += dfs(pos - 1, i, qd0 && i == 0, lim && i == up, cntt + (i == cur));
    }
    // if (!lim && !qd0) dp[pos][cntt] = s;
    return s;
}

int solve(int x, int c) {
    cur = c;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) dp[i][j] = -1;
    int len = 0;
    while (x) {
        num[len++] = x % 10;
        x /= 10;
    }
    return cnt[cur] = dfs(len - 1, 0, true, true, cur == 0);
}

int main() {
    cin >> a >> b;
    for (int i = 0; i <= 9; i++) {
        cout << solve(b, i) - solve(a - 1, i) << endl;
    }

    return 0;
}
