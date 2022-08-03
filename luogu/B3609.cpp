#include <bits/stdc++.h>
using namespace std;

const int N = 10001, M = 100001;
int n, m, cnt;
bool mp[N][N], vis[N];
stack<int> st;
vector<int> g[N];
int where[N];

inline void dfs(int x) {
    vis[x] = true;
    for (int i = 1; i <= n; i++) {
        if (mp[x][i] && !vis[i]) {
            dfs(i);
        }
    }
    st.push(x);
}

inline void ndfs(int x, int c) {
    vis[x] = true;
    where[x] = c;
    for (int i = 1; i <= n; i++) {
        if (mp[i][x] && !vis[i]) {
            ndfs(i, c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    memset(vis, 0, sizeof(vis));
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        if (!vis[x]) {
            cnt++;
            ndfs(x, cnt);
        }
    }
    memset(vis, 0, sizeof(vis));

    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            int p = where[i];
            cout << i << " ";
            for (int j = 1; j <= n; j++) {
                if (where[j] == p && i != j) {
                    cout << j << " ";
                    vis[j] = true;
                }
            }
            cout << endl;
        }
    }

    return 0;
}
