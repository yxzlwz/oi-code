#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int x, y, k, b, f[N][N];

int num[N];

int dfs(int pos, int pre, int ans, bool lim) {
    if (pos == -1) {
        if (ans == k) return 1;
        return 0;
    }
    if (ans > k) return 0;
    if (!lim && f[pos][ans] != -1) return f[pos][ans];
    int up = lim ? num[pos] : b - 1, s = 0;
    for (int i = 0; i <= min(1, up); i++) {
        s += dfs(pos - 1, i, ans + i, lim && i == up);
    }
    if (!lim) f[pos][ans] = s;
    return s;
}

int solve(int x) {
    int len = 0;
    while (x) {
        num[len++] = x % b;
        x /= b;
    }
    return dfs(len - 1, 0, 0, 1);
}

int main() {
    cin >> x >> y >> k >> b;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) f[i][j] = -1;
    cout << solve(y) - solve(x - 1) << endl;
    return 0;
}
