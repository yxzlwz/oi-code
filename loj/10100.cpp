#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int dfn[N], low[N], g[N][N], n, dfs;

set<int> gd;

void targin(int x, int fa) {
    int child = 0;
    dfn[x] = low[x] = ++dfs;
    for (int i = 1; i <= n; i++) {
        if (!g[x][i]) continue;
        if (!dfn[i]) {
            targin(i, fa);
            low[x] = min(low[x], low[i]);
            if (low[i] >= dfn[x] && x != fa) gd.insert(x);
            child++;
        } else
            low[x] = min(low[x], dfn[i]);
    }
    if (x == fa && child > 1) gd.insert(x);
}

int main() {
    while (1) {
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(g, 0, sizeof(g));
        gd.clear();
        cin >> n;
        if (!n) break;
        int m;
        while (1) {
            cin >> m;
            if (!m) break;
            int k;
            while (1) {
                cin >> k;
                g[m][k] = g[k][m] = 1;
                if (getchar() != ' ') break;
            }
        }
        dfs = 0;
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) targin(i, i);
        }
        cout << gd.size() << endl;
    }
}
