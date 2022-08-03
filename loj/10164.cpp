#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int a, b, f[N][N];

int num[N];

int dfs(int pos, int pre, bool lim) {
    if (pos == -1) return 1;
    if (!lim && f[pos][pre] != -1) return f[pos][pre];
    int up = lim ? num[pos] : 9, s = 0;
    for (int i = pre; i <= up; i++) {
        s += dfs(pos - 1, i, lim && i == up);
    }
    if (!lim) f[pos][pre] = s;
    return s;
}

int solve(int x) {
    int len = 0;
    while (x) {
        num[len++] = x % 10;
        x /= 10;
    }
    return dfs(len - 1, 0, 1);
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) f[i][j] = -1;
    while (cin >> a >> b) {
        cout << solve(b) - solve(a - 1) << endl;
    }
    return 0;
}
