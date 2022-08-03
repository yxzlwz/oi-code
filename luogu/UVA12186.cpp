#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, t;

struct EDGE {
    int v, next;
} edge[N];

int head[N], ecnt;

inline void add_edge(int u, int v) {
    edge[++ecnt] = (EDGE){v, head[u]};
    head[u] = ecnt;
}

int dfs(int u) {
    if (!head[u]) {
        return 1;
    }
    vector<int> x;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        x.push_back(dfs(v));
    }
    sort(x.begin(), x.end());
    double cc = x.size() * t / 100.0;
    int c, ans = 0;
    if (int(cc) == cc)
        c = cc;
    else
        c = cc + 1;
    for (int i = 0; i < c; i++) {
        ans += x[i];
    }
    return ans;
}

int main() {
    cin >> n >> t;
    while (n || t) {
        ecnt = 0;
        for (int i = 1; i <= n; i++) {
            int u;
            cin >> u;
            add_edge(u, i);
        }
        cout << dfs(0) << endl;
        cin >> n >> t;
    }
}
