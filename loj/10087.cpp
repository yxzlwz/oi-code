#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 1;

int n;

struct Edge {
    int to, w, next;
} edge[N << 2];
int head[N], ecnt;

inline void add_edge(int from, int to, int w) {
    edge[++ecnt] = (Edge){to, w, head[from]};
    head[from] = ecnt;
}

int dis[N];
bool vis[N];
queue<int> que;

int main() {
    for (int i = 1; i < N; i++) dis[i] = INT_MIN;
    cin >> n;
    for (int i = 0; i <= n + 2; i++) {
        add_edge(i, i + 1, 0);
        add_edge(i + 1, i, -1);
    }
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a++, b++;
        add_edge(a - 1, b, c);
    }

    int st = 0;

    dis[st] = 0;
    que.push(st);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        vis[cur] = false;
        for (int i = head[cur]; i; i = edge[i].next) {
            if (dis[edge[i].to] <= dis[cur] + edge[i].w) {
                dis[edge[i].to] = dis[cur] + edge[i].w;
                if (!vis[edge[i].to]) {
                    que.push(edge[i].to);
                }
                vis[edge[i].to] = true;
            }
        }
        cout << cur << endl;
    }

    for (int i = 1; i <= n; i++) cout << dis[i] << " ";

    return 0;
}
