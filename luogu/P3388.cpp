#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20005;
const int MAXM = 200005;

int m, n;

struct Edge {
    int v, next;
} edge[MAXM];

int head[MAXN], cnt, ans;

inline void addEdge(int u, int v) {
    ++cnt;
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int dfn[MAXN], low[MAXN], deep;
bool vis[MAXN], is_gd[MAXN];

void dfs(int x, int fa) {
    int child = 0;
    dfn[x] = low[x] = ++deep;
    for (int i = head[x]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            dfs(v, fa);
            low[x] = min(low[x], low[v]);
            if (low[v] >= dfn[x] && x != fa) is_gd[x] = true;
            child++;
        }
        low[x] = min(low[x], dfn[v]);
    }
    if (child >= 2 && x == fa) is_gd[x] = true;
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        if (is_gd[i]) ans++;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        if (is_gd[i]) cout << i << " ";
    }
    return 0;
}
