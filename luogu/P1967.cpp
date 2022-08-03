#include <bits/stdc++.h>
using namespace std;

const int N = 10001, M = 50001, LOG = 19;

class BCJ {
   private:
    int f[N];

   public:
    void init() {
        for (int i = 0; i < N; i++) f[i] = i;
    }
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    void merge(int x, int y) { f[find(x)] = find(y); }
} bcj;

int n, m, q;

struct EDGE {
    int u, v, w, next;
} tree_edge[M << 1], edge[M << 1];

int head[N], ecnt;

void add_edge(int u, int v, int w) {
    edge[++ecnt].v = v;
    edge[ecnt].w = w;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
}

bool cmp(EDGE a, EDGE b) { return a.w > b.w; }

int father[N][LOG], min_edge[N][LOG], deep[N];

void dfs(int x, int fa, int w, int d) {
    father[x][0] = fa;
    min_edge[x][0] = w;
    deep[x] = d;
    for (int i = 1; i < LOG; i++) {
        father[x][i] = father[father[x][i - 1]][i - 1];
        min_edge[x][i] =
            min(min_edge[x][i - 1], min_edge[father[x][i - 1]][i - 1]);
    }
    for (int i = head[x]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa) continue;
        dfs(v, x, edge[i].w, d + 1);
    }
}

int lca(int x, int y) {
    int minn = INT_MAX;
    if (deep[x] < deep[y]) swap(x, y);
    for (int i = LOG - 1; i >= 0; i--)
        if (deep[father[x][i]] >= deep[y]) {
            minn = min(minn, min_edge[x][i]);
            x = father[x][i];
        }
    for (int i = LOG - 1; i >= 0; i--)
        if (father[x][i] != father[y][i]) {
            minn = min(minn, min(min_edge[x][i], min_edge[y][i]));
            x = father[x][i], y = father[y][i];
        }
    return min(min(min_edge[x][0], min_edge[y][0]), minn);
}

int main() {
    memset(min_edge, 0x3f, sizeof(min_edge));
    bcj.init();

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree_edge[i] = (EDGE){u, v, w, 0};
    }
    sort(tree_edge + 1, tree_edge + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        int u = tree_edge[i].u, v = tree_edge[i].v;
        if (bcj.find(u) != bcj.find(v)) {
            bcj.merge(u, v);
            add_edge(u, v, tree_edge[i].w);
            add_edge(v, u, tree_edge[i].w);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!deep[i]) dfs(i, 0, INT_MAX, 1);
    }

    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (bcj.find(x) != bcj.find(y)) {
            cout << -1 << endl;
            continue;
        }
        cout << lca(x, y) << endl;
    }
    return 0;
}
