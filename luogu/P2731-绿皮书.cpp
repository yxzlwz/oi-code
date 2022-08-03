#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define N 501
using namespace std;

int n, g[N][N], du[N], path[N], beginn = INF, cnt;

void dfs(int i) {
    for (int j = beginn; j <= n; j++)
        if (g[i][j]) {
            g[i][j]--;
            g[j][i]--;
            dfs(j);
        }
    path[cnt++] = i;
}

int main() {
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y]++;
        g[y][x]++;
        du[x]++;
        du[y]++;
        n = max(n, max(x, y));
        beginn = min(beginn, min(x, y));
    }
    int start = beginn;
    for (int i = beginn; i <= n; i++) {
        if (du[i] % 2 == 1) {
            start = i;
            break;
        }
    }
    dfs(start);
    for (int i = cnt - 1; i >= 0; i--) cout << path[i] << endl;
    return 0;
}