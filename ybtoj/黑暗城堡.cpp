#include <bits/stdc++.h>
using namespace std;

int n, m, s[1001][1001], d[1001];
long long ans = 1;
bool vis[1001];

const long long mod = (1 << 31) - 1;

int main() {
    memset(s, 0x7f7f7f7f, sizeof(s));
    memset(d, 0x7f7f7f7f, sizeof(d));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        s[x][y] = s[y][x] = min(s[x][y], w);
    }
    d[1] = 0;
    // vis[1] = true;
    // for (int i = 2; i <= n; i++) d[i] = s[1][i];
    for (int i = 1; i <= n; i++) {
        int minn = 0x7f7f7f7f, u = 0;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && d[j] <= minn) {
                minn = d[j];
                u = j;
            }
        }
        vis[u] = true;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && d[j] > d[u] + s[u][j]) {
                d[j] = d[u] + s[u][j];
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     printf("%d:%d ", i, d[i]);
    // }
    // cout << endl;
    for (int i = 2; i <= n; i++) {
        if (d[i] == 0x7f7f7f7f) {
            cout << 0 << endl;
            return 0;
        }
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (d[i] == d[j] + s[i][j]) cnt++;
        }
        ans = ans * cnt % mod;
        // cout << i << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
