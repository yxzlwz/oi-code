#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int X = 0;
    bool flag = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') flag = 0;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        X = (X << 1) + (X << 3) + ch - '0';
        ch = getchar();
    }
    if (flag) return X;
    return ~(X - 1);
}

const int N = 100005, M = 500005;
struct edge {
    int nxt, to, dis;
} e[M * 2];
queue<int> q;
int n, m;
int head[N], dis[N], cnt;
bool vis[N];

void add(int u, int v, int w) {
    e[++cnt].nxt = head[u];
    e[cnt].to = v;
    e[cnt].dis = w;
    head[u] = cnt;
}

void spfa() {
    memset(dis, 0x3f, sizeof(dis));
    q.push(1);
    dis[1] = 0;
    vis[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to;
            if (dis[x] + e[i].dis < dis[y]) {
                dis[y] = dis[x] + e[i].dis;
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
}

int main() {
    n = read();
    m = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
        add(v, u, w);
    }
    spfa();
    cout << dis[n] << endl;
    return 0;
}
