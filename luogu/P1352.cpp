#include <bits/stdc++.h>
using namespace std;

const int N = 6001;

int n, r[N], dp[N][2];

bool vis[N];

struct EDGE {
    int v, next;
} edge[N << 1];

int ecnt, head[N];

inline void add_edge(int u, int v) {
    edge[++ecnt] = (EDGE){v, head[u]};
    head[u] = ecnt;
}

int dfs(int u) {
    if (!head[u]) {
        dp[u][0] = 0;
        dp[u][1] = r[u];
        return 0;
    }
    dp[u][1] = r[u];
    vis[u] = true;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (vis[v]) continue;
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    return 0;
}

int main() {
    cin >> n;
    set<int> hm;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
        hm.insert(i);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(v, u);
        hm.erase(u);
    }

    int root = *hm.begin();
    dfs(root);

    cout << max(dp[root][0], dp[root][1]) << endl;

    return 0;
}
