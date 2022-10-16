#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100001, M = 500001;

int n, m;
int head[N], ecnt;
struct EDGE {
    int v, next;
} edge[M << 1];

void adde(int u, int v) {
    edge[++ecnt] = EDGE{v, head[u]};
    head[u] = ecnt;
}

int dfn[N], low[N], cnt, color[N], cocnt, rd[N];
stack<int> st;
void dfs(int x, int fa) {
    dfn[x] = low[x] = ++cnt;
    st.push(x);
    for (int i = head[x]; i; i = edge[i].next) {
        const int v = edge[i].v;
        if (!dfn[v]) {
            dfs(v, x);
            low[x] = min(low[x], low[v]);
        } else if (!color[v]) {
            low[x] = min(low[x], dfn[v]);
        }
    }
    if (dfn[x] == low[x]) {
        color[x] = ++cocnt;
        while (st.top() != x) {
            color[st.top()] = cocnt;
            st.pop();
        }
        st.pop();
    }
    return;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adde(x, y);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) dfs(i, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = edge[j].next) {
            int v = edge[j].v;
            if (color[i] != color[v]) {
                rd[color[v]]++;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= cocnt; i++) {
        if (rd[i] == 0) {
            ans++;
        }
    }
    if (!ans) ans = 1;
    cout << ans << endl;

    return 0;
}