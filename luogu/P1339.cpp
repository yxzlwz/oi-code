#include <bits/stdc++.h>
using namespace std;

const int N = 100001, M = 200001;

typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii> > q;

int head[N], ecnt;

struct EDGE {
    int to, next, w;
} edge[M];

inline void add(int u, int v, int w) {
    edge[++ecnt] = (EDGE){v, head[u], w};
    head[u] = ecnt;
}

int n, m, s, t, d[N];
bool vis[N];

int main() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].to;
            if (d[v] > d[u] + edge[i].w) {
                d[v] = d[u] + edge[i].w;
                q.push(make_pair(d[v], v));
            }
        }
    }
    cout << d[t];
}
