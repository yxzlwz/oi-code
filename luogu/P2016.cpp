#include <bits/stdc++.h>
using namespace std;

const int N = 1501;

int n, dp[N][2];

bool vis[N];

struct NODE {
    int v, next;
} edge[N << 1];

int head[N], ecnt;

inline void add_edge(int u, int v) {
    edge[++ecnt] = (NODE){v, head[u]};
    head[u] = ecnt;
}

void dfs(int u) {
    vis[u] = true;
    dp[u][0] = 0;
    dp[u][1] = 1;

    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (vis[v]) continue;
        dfs(v);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, k;
        cin >> u >> k;
        while (k--) {
            int v;
            cin >> v;
            add_edge(u, v);
            add_edge(v, u);
        }
    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}
