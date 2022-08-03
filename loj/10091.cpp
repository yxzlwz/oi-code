#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const int MAXM = 100005;

int n, m;

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

int dfn[MAXN], low[MAXN], color[MAXN], du[MAXN], cs, deep;
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
        color[x] = ++cs;
        while (st.top() != x) {
            color[st.top()] = cs;
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

    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = edge[j].next) {
            if (color[i] != color[edge[j].v]) {
                du[color[i]]++;
            }
        }
    }

    int flag = 0, ans_col = 0;

    for (int i = 1; i <= cs; i++) {
        if (du[i] == 0) {
            if (flag) {
                cout << "0" << endl;
                return 0;
            }
            flag = 1;
            ans_col = i;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == ans_col) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
