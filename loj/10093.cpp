// https://loj.ac/p/10093

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101, MAXM = 10001;

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

int n, dfn[MAXN], low[MAXN], color[MAXN], color_cnt, deep, rd[MAXN], cd[MAXN];

stack<int> st;

void tarjan(int x) {
    st.push(x);
    dfn[x] = low[x] = ++deep;
    for (int i = head[x]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            tarjan(v);
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
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        while (u) {
            addEdge(i, u);
            cin >> u;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    if (color_cnt == 1) {
        cout << "1\n0\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = edge[j].next) {
            int v = edge[j].v;
            if (color[i] != color[v]) {
                rd[color[v]]++;
                cd[color[i]]++;
            }
        }
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= color_cnt; i++) {
        if (rd[i] == 0) ans1++;
        if (cd[i] == 0) ans2++;
    }
    cout << ans1 << endl << max(ans1, ans2) << endl;

    return 0;
}
