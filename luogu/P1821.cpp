#include <bits/stdc++.h>
using namespace std;

int f[1001][1001];

int main() {
    int n, m, u, v, w, x;
    cin >> n >> m >> x;
    memset(f, 0x7f7f7f7f, sizeof(f));
    while (m--) {
        cin >> u >> v >> w;
        f[u][v] = w;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == k || k == j || i == j) continue;
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    int maxnum = 0;

    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        maxnum = max(maxnum, f[i][x] + f[x][i]);
    }

    cout << maxnum;

    return 0;
}