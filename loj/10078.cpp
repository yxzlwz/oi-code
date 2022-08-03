#include <bits/stdc++.h>
using namespace std;

const int N = 50001, M = 100001;

struct EDGE {
    int v, w, next;
} edge[M << 1];

int head[N], ecnt;
bool vis[N];

inline void adde(int u, int v, int w) {
    edge[++ecnt].next = head[u];
    edge[ecnt].v = v;
    edge[ecnt].w = w;
    head[u] = ecnt;
    edge[++ecnt].next = head[v];
    edge[ecnt].v = u;
    edge[ecnt].w = w;
    head[v] = ecnt;
}

int n, m, sta[6], dd[6][N], ans;

struct node {
    int v, w;
    friend bool operator<(const node &a, const node &b) { return a.w > b.w; }
};

void dij(int x, int *d) {
    memset(vis, 0, sizeof(vis));
    priority_queue<node> q;
    d[x] = 0;
    q.push((node){x, 0});
    while (!q.empty()) {
        int t = q.top().v;
        q.pop();
        if (vis[t]) continue;
        vis[t] = 1;
        for (int i = head[t]; i; i = edge[i].next) {
            int v = edge[i].v, w = edge[i].w;
            if (d[v] > d[t] + w) {
                d[v] = d[t] + w;
                q.push((node){v, d[v]});
            }
        }
    }
}

void dfs(int x, int a) {
    for (int i = 1; i <= 5; i++) {
        if (!vis[i]) break;
        if (i == 5) {
            ans = min(ans, a);
            return;
        }
    }
    for (int i = 1; i <= 5; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        // dfs(x, a + 2 * dd[x][sta[i]]);
        dfs(i, a + dd[x][sta[i]]);
        vis[i] = 0;
    }
}

int main() {
    // freopen("E:/Desktop/newyear6.in", "r", stdin);
    // freopen("newyear.out", "w", stdout);
    ans = INT_MAX;
    memset(dd, 0x3f, sizeof(dd));
    cin >> n >> m;
    sta[0] = 1;
    for (int i = 1; i <= 5; i++) cin >> sta[i];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adde(u, v, w);
    }

    for (int i = 0; i <= 5; i++) {
        dij(sta[i], dd[i]);
    }

    memset(vis, 0, sizeof(vis));
    dfs(0, 0);
    cout << ans << endl;

    return 0;
}
