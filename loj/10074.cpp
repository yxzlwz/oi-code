#include <bits/stdc++.h>
using namespace std;

const int N = 1001, P = 2001;

int n, p, k;
struct Edge {
    int to, w, next;
} edge[P << 1];
struct node {
    int to, w;
    friend bool operator<(const node &a, const node &b) { return a.w > b.w; }
};
int head[N], ecnt;
int dis[N];
bool vis[N];

inline void add_edge(int from, int to, int w) {
    edge[++ecnt] = (Edge){to, w, head[from]};
    head[from] = ecnt;
    edge[++ecnt] = (Edge){from, w, head[to]};
    head[to] = ecnt;
}

priority_queue<node> q;

int dij(int mid) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[1] = 0;
    q.push((node){1, 0});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (vis[t.to]) continue;
        vis[t.to] = true;
        for (int i = head[t.to]; i; i = edge[i].next) {
            int w = (edge[i].w > mid);
            if (dis[edge[i].to] > dis[t.to] + w) {
                dis[edge[i].to] = dis[t.to] + w;
                q.push((node){edge[i].to, dis[edge[i].to]});
            }
        }
    }
    return dis[n];
}

int main() {
    cin >> n >> p >> k;
    int maxx = 0;
    while (p--) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
        maxx = max(maxx, c);
    }
    int l = 0, r = maxx;
    while (l < r) {
        int mid = (l + r) >> 1;
        int ans = dij(mid);
        if (ans == 0x3f3f3f3f) {
            cout << -1;
            return 0;
        }
        if (ans > k)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l;
    return 0;
}