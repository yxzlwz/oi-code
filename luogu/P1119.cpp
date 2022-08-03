#include <bits/stdc++.h>
using namespace std;

const int N = 201;

int n, m, q, t[N];
int mp[N][N];

int main() {
    memset(mp, 0x3f, sizeof(mp));

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        mp[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u][v] = mp[v][u] = w;
    }

    cin >> q;
    int k = 0;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        for (; t[k] <= c && k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mp[i][j] = mp[j][i] = min(mp[i][j], mp[i][k] + mp[k][j]);
                }
            }
        }
        if (mp[a][b] == 0x3f3f3f3f || t[a] > c || t[b] > c)
            cout << -1 << endl;
        else
            cout << mp[a][b] << endl;
    }
}
