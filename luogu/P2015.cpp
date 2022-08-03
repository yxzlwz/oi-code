#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n, q;

struct EDGE {
    int v, w, next;
} edge[N << 1];

int ecnt, head[N];

void dfs()

int main() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[ecnt] = (EDGE){v, w, head[u]};
        head[u] = ecnt++;
        edge[ecnt] = (EDGE){u, w, head[v]};
        head[v] = ecnt++;
    }
    return 0;
}
