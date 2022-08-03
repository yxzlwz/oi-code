#include <bits/stdc++.h>
using namespace std;

const int N = 2000001;

vector<int> e[N], lt[N];

int n, m, dfn[N], low[N], tot, ltcnt;

stack<int> s;

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tot;
    s.push(u);
    int children = 0;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (!dfn[v]) {
            children++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                ltcnt++;
                while (s.top() != v) {
                    lt[ltcnt].push_back(s.top());
                    s.pop();
                }
                lt[ltcnt].push_back(s.top());
                s.pop();
                lt[ltcnt].push_back(u);
            }
        } else if (v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (fa == 0 && children == 0) {
        lt[++ltcnt].push_back(u);
    }
}

int main() {
    // freopen("E:/Downloads/P8435_1.in", "r", stdin);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, 0);
        }
    }

    cout << ltcnt << endl;
    for (int i = 1; i <= ltcnt; i++) {
        printf("%d ", lt[i].size());
        for (int j = 0; j < lt[i].size(); j++) printf("%d ", lt[i][j]);
        printf("\n");
    }
}
