#include <bits/stdc++.h>
using namespace std;

const int N = 100001, M = 500001;

int ecnt, memcnt;
long long tot;

inline void read(int &a) {
    a = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        a = (a << 3) + (a << 1) + c - '0';
        c = getchar();
    }
}

class BCJ {  // 供kruscal使用的并查集，建类可以更好地处理变量名
   private:
    int f[M];

   public:
    void init() {
        for (int i = 0; i < M; i++) f[i] = i;
    }
    int find(int x) {
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        f[y] = x;
    }
} bcj;

struct Edge {
    int from, to, w;
} edge[M], e[M];  // edge为所有边的信息，e为不在最小生成树中的边

bool cmp(Edge x, Edge y) {
    // 对所有边进行sort排序以供kruscal算法使用
    return x.w < y.w;
}

class Mem {
   public:
    struct POINT {
        // 点的相关信息
        int head, deep, fa[21];
        long long max1[21], max2[21];
    } p[N];
    int size;  // 边的数量
    struct EDGE {
        // 边的相关信息
        int to, w, next;
    } e[N * 2];
    void init() {
        size = 0;
        for (int i = 0; i < N; i++) {
            p[i].head = p[i].deep = 0;
            memset(p[i].fa, 0, sizeof(p[i].fa));
            memset(p[i].max1, 0, sizeof(p[i].max1));
            memset(p[i].max2, LONG_LONG_MAX, sizeof(p[i].max2));
        }
    }
    void add(Edge t) {
        ++size;
        e[size].next = p[t.from].head;
        e[size].to = t.to;
        e[size].w = t.w;
        p[t.from].head = size;
        ++size;
        e[size].next = p[t.to].head;
        e[size].to = t.from;
        e[size].w = t.w;
        p[t.to].head = size;
    }
} mem;

void dfs(int cur, int fa) {
    // 深度优先搜索，处理每个点的父节点信息和最大值信息
    mem.p[cur].deep = mem.p[fa].deep + 1;
    for (int i = 0; i <= 19; i++) {
        mem.p[cur].fa[i + 1] = mem.p[mem.p[cur].fa[i]].fa[i];
        mem.p[cur].max1[i + 1] =
            max(mem.p[cur].max1[i], mem.p[mem.p[cur].fa[i]].max1[i]);
        if (mem.p[cur].max1[i] == mem.p[mem.p[cur].fa[i]].max1[i])
            mem.p[cur].max2[i + 1] =
                max(mem.p[cur].max2[i], mem.p[mem.p[cur].fa[i]].max2[i]);
        else if (mem.p[cur].max1[i] < mem.p[mem.p[cur].fa[i]].max1[i])
            mem.p[cur].max2[i + 1] =
                max(mem.p[cur].max1[i], mem.p[mem.p[cur].fa[i]].max2[i]);
        else
            mem.p[cur].max2[i + 1] =
                max(mem.p[cur].max2[i], mem.p[mem.p[cur].fa[i]].max1[i]);
    }
    for (int i = mem.p[cur].head; i; i = mem.e[i].next) {
        // 对所有子节点进行dfs处理
        if (mem.e[i].to == fa) continue;
        mem.p[mem.e[i].to].fa[0] = cur;
        mem.p[mem.e[i].to].max1[0] = mem.e[i].w;
        mem.p[mem.e[i].to].max2[0] = INT_MIN;
        dfs(mem.e[i].to, cur);
    }
}

int lca(int x, int y) {
    // lca算法求两点的最近公共祖先
    long long ans = 0;
    if (mem.p[x].deep < mem.p[y].deep) swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (mem.p[mem.p[x].fa[i]].deep >= mem.p[y].deep) x = mem.p[x].fa[i];
        if (x == y) return x;
    }
    for (int i = 20; i >= 0; i--) {
        if (mem.p[x].fa[i] != mem.p[y].fa[i]) {
            x = mem.p[x].fa[i];
            y = mem.p[y].fa[i];
        }
    }
    return mem.p[x].fa[0];
}

long long qmax(int x, int y, int w) {
    // 求两点间的最大边
    long long ans = LONG_LONG_MIN;
    for (int i = 20; i >= 0; i--) {
        if (mem.p[mem.p[x].fa[i]].deep >= mem.p[y].deep) {
            if (w != mem.p[x].max1[i]) {
                ans = max(ans, mem.p[x].max1[i]);
            } else {
                ans = max(ans, mem.p[x].max2[i]);
            }
            x = mem.p[x].fa[i];
        }
    }
    return ans;
}

int main() {
    bcj.init();
    mem.init();
    int n, m;
    read(n);
    read(m);
    for (int i = 1; i <= m; i++) {
        read(edge[i].from);
        read(edge[i].to);
        read(edge[i].w);
    }
    sort(edge + 1, edge + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        if (bcj.find(edge[i].from) != bcj.find(edge[i].to)) {
            bcj.merge(edge[i].from, edge[i].to);
            tot += edge[i].w;
            mem.add(edge[i]);
        } else {
            // 记录未加入最小生成树的边
            ecnt++;
            e[ecnt] = edge[i];
        }
    }

    long long ans = LONG_LONG_MAX;
    dfs(1, 0);
    for (int i = 1; i <= ecnt; i++) {
        if (e[i].from == e[i].to) continue;
        int t = lca(e[i].from, e[i].to);
        long long res =
            max(qmax(e[i].from, t, e[i].w), qmax(e[i].to, t, e[i].w));
        if (res < 0) continue;
        ans = min(ans, tot + e[i].w - res);
    }
    cout << ans << endl;
    return 0;
}
