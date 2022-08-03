#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int n, g[N][N];

int vis[N], c[N], color[N], color_cnt, rd[N];

void dfs(int x, int f) {
    c[x] = f;
    for (int i = 1; i <= n; i++) {
        if (g[x][i] && !c[i]) {
            dfs(i, f);
        }
    }
}

void ndfs(int x, int f) {
    color[x] = f;
    for (int i = 1; i <= n; i++) {
        if (g[i][x] && !color[i] && c[i] == c[x]) {
            ndfs(i, f);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> g[i][j];

    for (int i = 1; i <= n; i++) {
        if (!c[i]) {
            ++color_cnt;
            dfs(i, color_cnt);
        }
    }

    color_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            ++color_cnt;
            ndfs(i, color_cnt);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] && color[i] != color[j]) {
                rd[color[j]]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= color_cnt; i++) {
        if (rd[i] == 0) ans++;
    }
    cout << max(1, ans) << endl;

    return 0;
}
