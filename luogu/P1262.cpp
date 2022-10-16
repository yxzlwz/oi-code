#include <bits/stdc++.h>
#define DEBUG if (false)
using namespace std;

const int N = 3001;

int n, p, r, jg[N];

int head[N], ecnt, rd[N], headd[N], ecntt, rdd[N];
struct EDGE {
    int v, w, next;
} edge[50001], edgee[50001];

stack<int> st;
int deep, dfn[N], low[N], color[N], color_cnt;

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
    freopen("/mnt/d/Desktop/P1262_4.in", "r", stdin);
    cin >> n >> p;
    memset(jg, -1, sizeof(jg));
    for (int i = 1; i <= p; i++) {
        int a, b;
        cin >> a >> b;
        jg[a] = b;
        // edge[++ecnt] = (EDGE){a, b, head[0]};
        // head[0] = ecnt;
    }
    cin >> r;
    for (int i = 1; i <= r; i++) {
        int u, v;
        cin >> u >> v;
        edge[++ecnt] = (EDGE){v, 0, head[u]};
        head[u] = ecnt;
        rd[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs(i);
    }

    for (int u = 1; u <= n; u++) {
        if (!color[u] && !rd[u] && jg[u] == -1) {
            cout << "NO\n" << u << endl;
            return 0;
        } else if (!color[u])
            color[u] = ++color_cnt;
    }

    int ans = 0;
    for (int i = 1; i <= color_cnt; i++) {
        DEBUG printf("i: %d\n", i);
        int minn = INT_MAX;
        for (int j = 1; j <= n; j++) {
            if (color[j] == i) {
                DEBUG printf("  j: %d\n", j);
                for (int k = head[j]; k; k = edge[k].next) {
                    edgee[++ecntt] =
                        (EDGE){color[edge[k].v], edge[k].w, headd[i]};
                    headd[i] = ecntt;
                    rdd[color[edge[k].v]]++;
                }
                if (jg[j] != -1) minn = min(minn, jg[j]);
            }
        }
        DEBUG printf(" minn: %d\n", minn);
        if (!rdd[i]) ans += minn;
    }

    cout << "YES\n" << ans << endl;

    return 0;
}
