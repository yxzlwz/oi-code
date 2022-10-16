#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 2e5 + 10, M = 5e5 + 10;

int n, m, a, b, du[N];
bool block[N];
priority_queue<pii, vector<pii>, greater<pii>> que;

int head[N], ecnt;
struct EDGE {
    int v, next;
} edge[M << 1];
void adde(int u, int v) {
    edge[++ecnt] = EDGE{v, head[u]};
    head[u] = ecnt;
}

int dfn[N], low[N], deep;
bool is_gd[N];
stack<int> st;
void tarjan(int x, int fa) {
    st.push(x);
    dfn[x] = low[x] = ++deep;

    return;
}

int main() {
    cin >> n >> m >> a >> b;
    while (a || b) {
        adde(a, b), adde(b, a);
        du[a]++, du[b]++;
        cin >> a >> b;
    }
    for (int i = 1; i <= n; i++) {
        que.push(make_pair(du[i], i));
    }

    return 0;
}