#include <cstdio>
#include <iostream>
using namespace std;
const int N = 500010;
struct edge {
    int v, next;
} mem[N * 2];
int head[N] = {0}, size = 0;

inline void addEdge(int u, int v) {
    ++size;
    mem[size].next = head[u];
    mem[size].v = v;
    head[u] = size;
}
int dep[N] = {0}, fa[N][21] = {0};

void dfs(int u, int father) {
    dep[u] = dep[father] + 1;

    for (int i = 0; i <= 19; i++) fa[u][i + 1] = fa[fa[u][i]][i];
    for (int e = head[u]; e; e = mem[e].next) {
        int v = mem[e].v;
        if (v == father) continue;
        fa[v][0] = u;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
        if (x == y) return x;
    }
    for (int i = 20; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    dep[0] = -1;
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        int a1 = lca(u, v), a2 = lca(u, w), a3 = lca(v, w), a;
        if (a1 == a2)
            a = a3;
        else if (a1 == a3)
            a = a2;
        else
            a = a1;
        cout << a << " "
             << (dep[a] + dep[u] - 2 * dep[lca(a, u)]) +
                    (dep[a] + dep[v] - 2 * dep[lca(a, v)]) +
                    (dep[a] + dep[w] - 2 * dep[lca(a, w)])
             << endl;
    }
    return 0;
}
