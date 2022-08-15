#include <bits/stdc++.h>
using namespace std;

int n, m, k;

struct EDGE {
    int to, w, next;
} edge[20001];

int head[1001], ecnt;

inline void add_edge(int u, int v, int w) {
    edge[++ecnt] = (EDGE){v, w, head[u]};
    head[u] = ecnt;
}

bool dij() {
    int dis[1001];
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
                q.push(v);
            }
        }
    }
    return dis[n] < k;
}

int main() {
    cin >> n >> m >> k;
    int maxx = 0;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
        maxx = max(maxx, w);
    }
    int l = 0, r = maxx + 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int p = head[i];
            while (p) {
                if (edge[p].w > mid) cnt++;
                p = edge[p].next;
            }
        }
        if (cnt <= k)
            r = mid;
        else
            l = mid + 1;
    }
}