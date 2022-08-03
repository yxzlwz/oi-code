#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const int MAXM = 100005;

int m, n;

struct Edge {
    int v, next;
} edge[MAXM];

int head[MAXN], cnt;

inline void addEdge(int u, int v) {
    ++cnt;
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int dfn[MAXN], low[MAXN], color[MAXN], color_cnt, deep;
bool vis[MAXN];
stack<int> st;

void dfs(int x) {
    st.push(x);
    dfn[x] = low[x] = ++deep;
    for (int i = head[x]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            dfs(v);
            low[x] = min(low[x], low[v]);
        } else if (!color[v])
            low[x] = min(low[x], dfn[v]);
    }
    if (dfn[x] == low[x]) {
        color[x] = ++color_cnt;
        while (st.top() != x) {
            color[st.top()] = color_cnt;
            st.pop();
        }
        st.pop();
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs(i);
    }
    cout << color_cnt << endl;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            for (int j = 1; j <= n; j++) {
                if (color[i] == color[j]) {
                    vis[j] = true;
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
