#include <bits/stdc++.h>
using namespace std;

const int N = 500001, M = 500001, L = 20;

struct Edge {
    int to, next;
} edge[N << 1];

int head[N], ecnt;

inline void read(int &x) {
    x = 0;
    char ch = getchar();
    short flag = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    x *= flag;
}

inline void add(int u, int v) {
    edge[++ecnt] = (Edge){v, head[u]};
    head[u] = ecnt;
}
int n, m, s;

int pre[N][L], d[N];

void bfs() {
    d[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].to;
            if (d[v]) continue;
            d[v] = d[u] + 1;
            pre[v][0] = u;
            for (int i = 1; i < L; i++) {
                pre[v][i] = pre[pre[v][i - 1]][i - 1];
            }
            q.push(v);
        }
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    for (int i = L - 1; i >= 0; i--) {
        if (d[pre[x][i]] >= d[y]) x = pre[x][i];
    }
    if (x == y) return x;
    for (int i = L - 1; i >= 0; i--) {
        if (pre[x][i] != pre[y][i]) {
            x = pre[x][i];
            y = pre[y][i];
        }
    }
    return pre[x][0];
}

int main() {
    read(n);
    read(m);
    read(s);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u);
        read(v);
        add(u, v);
        add(v, u);
    }
    bfs();
    while (m--) {
        int x, y;
        read(x);
        read(y);
        cout << lca(x, y) << endl;
    }
}
