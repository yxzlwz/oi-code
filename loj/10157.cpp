#include <bits/stdc++.h>
using namespace std;

const int N = 1501;

int n, dp[N][3], w[N];

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
    dp[u][1] = w[u];
    dp[u][2] = 0;

    bool ok = false;
    int d = 0x3f3f3f3f;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (vis[v]) continue;
        dfs(v);
        dp[u][0] += min(dp[v][1], dp[v][2]);
        dp[u][1] += min(min(dp[v][0], dp[v][1]), dp[v][2]);
        if (dp[v][1] < dp[v][2]) {
            dp[u][2] += dp[v][1];
            ok = true;
        } else {
            dp[u][2] += dp[v][2];
            d = min(d, dp[v][1] - dp[v][2]);
        }
    }

    if (!ok) dp[u][2] += d;

    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, m;
        cin >> u >> w[i] >> m;
        while (m--) {
            int v;
            cin >> v;
            add_edge(u, v);
            add_edge(v, u);
        }
    }

    dfs(1);

    cout << min(dp[1][1], dp[1][2]) << endl;

    return 0;
}
