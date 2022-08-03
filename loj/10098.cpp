#include <bits/stdc++.h>
using namespace std;

const int N = 5001, M = 10001;

int dfn[N], low[N], deep, color[N], color_cnt, n, m, cnt, du[N], head[N];

stack<int> st;

struct EDGE {
    int v, next;
} edge[M << 1];

void adde(int u, int v) {
    edge[++cnt].next = head[u];
    edge[cnt].v = v;
    head[u] = cnt;
    edge[++cnt].next = head[v];
    edge[cnt].v = u;
    head[v] = cnt;
}

void tarjan(int x) {
    dfn[x] = low[x] = ++deep;
    st.push(x);
    for (int i = head[x]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        } else if (!color[v])
            low[x] = min(low[x], dfn[v]);
    }
    if (low[x] == dfn[x]) {
        color[x] = ++color_cnt;
        while (st.top() != x) {
            color[st.top()] = color_cnt;
            st.pop();
        }
        st.pop();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adde(u, v);
        adde(v, u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    cout << color_cnt << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = edge[j].next) {
            int v = edge[j].v;
            if (color[i] != color[v]) {
                du[color[i]]++;
                du[color[v]]++;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= color_cnt; i++) {
        cout << du[i] << " ";
        if (du[i] == 1) ans++;
    }
    cout << ans << endl;

    return 0;
}
