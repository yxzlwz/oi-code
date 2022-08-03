// 2018 高一

#include <bits/stdc++.h>
using namespace std;

const int N = 100001, M = 500001;

typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii> > q1, q2;

int head1[N], head2[N], ecnt1, ecnt2;
struct EDGE {
    int to, next;
} edge1[M << 1], edge2[M << 1];

inline void add(int u, int v, EDGE *edge, int &ecnt, int *head) {
    edge[++ecnt] = (EDGE){v, head[u]};
    head[u] = ecnt;
}

int n, m, a[N], d1[N], d2[N];
bool vis1[N], vis2[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 1) {
            add(x, y, edge1, ecnt1, head1);
            add(y, x, edge2, ecnt2, head2);
        } else {
            add(x, y, edge1, ecnt1, head1);
            add(y, x, edge1, ecnt1, head1);
            add(x, y, edge2, ecnt2, head2);
            add(y, x, edge2, ecnt2, head2);
        }
    }
    memset(d1, 0x3f, sizeof(d1));
    memset(d2, 0, sizeof(d2));

    d1[1] = a[1];
    q1.push(make_pair(d1[1], 1));
    while (!q1.empty()) {
        int u = q1.top().second;
        q1.pop();
        if (vis1[u]) continue;
        vis1[u] = 1;
        for (int i = head1[u]; i; i = edge1[i].next) {
            int v = edge1[i].to;
            d1[v] = min(d1[v], min(d1[u], a[v]));
            q1.push(make_pair(d1[v], v));
        }
    }

    d2[n] = a[n];
    q2.push(make_pair(-d2[n], n));
    while (!q2.empty()) {
        int u = q2.top().second;
        q2.pop();
        if (vis2[u]) continue;
        vis2[u] = 1;
        for (int i = head2[u]; i; i = edge2[i].next) {
            int v = edge2[i].to;
            d2[v] = max(d2[v], max(d2[u], a[v]));
            q2.push(make_pair(-d2[v], v));
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, d2[i] - d1[i]);
    }
    cout << ans << endl;
}
