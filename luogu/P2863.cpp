#include <bits/stdc++.h>
const int MAXN = 10001, MAXM = 50001;

int head[MAXN], ecnt;

struct Edge {
    int v, next;
} edge[MAXM];

inline void addEdge(int u, int v) {
    ++ecnt;
    edge[ecnt].v = v;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
}

int n, m,
    dfn[MAXN],               //
    low[MAXN],               //
    color[MAXN], color_cnt,  //
    deep;

std::stack<int> st;

void tarjan(int x) {
    st.push(x);
    dfn[x] = low[x] = ++deep;
    for (int i = head[x]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[x] = std::min(low[x], low[v]);
        } else if (!color[v])
            low[x] = std::min(low[x], dfn[v]);
    }
    if (dfn[x] == low[x]) {
        color[x] = ++color_cnt;
        while (st.top() != x) {
            color[st.top()] = color_cnt;
            st.pop();
        }
        st.pop();
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        addEdge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    int ans = 0;
    for (int i = 1; i <= color_cnt; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (color[j] == i) cnt++;
        }
        if (cnt > 1) ans++;
    }

    std::cout << ans;

    return 0;
}
