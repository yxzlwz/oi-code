#include <bits/stdc++.h>
#define DEBUG if (false)
#define int long long
using namespace std;

typedef pair<int, int> pii;

const int N = 2001;

int n, f[N][N], g[N][N];
pii a, p[N], q[N];
bool used_q[N];

bool cmp1(const pii &x, const pii &y) {
    return double(x.second) / double(x.first) >
           double(y.second) / double(y.first);
}
bool cmp2(const pii &x, const pii &y) { return x > y; }

signed main() {
    cin >> n;
    int guagou = 1, ans = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a.first >> a.second;
        if (a.first && a.second >= 0)
            guagou += a.first - 1, ans += a.second;
        else if (a.first > 1)
            --a.first, p[++cnt1] = a;  // 有挂钩
        else if (a.second > 0)
            q[++cnt2] = a;  // 稳赚不赔
    }
    sort(p + 1, p + cnt1 + 1, cmp1);
    sort(q + 1, q + cnt2 + 1, cmp2);

    int i = 1, j = 1;

    for (int k = 0; k <= cnt1; k++)
        for (int l = 0; l <= cnt2 - j; l++) f[k][l] = -0x7f7f7f7f;
    f[0][0] = 0;
    for (int k = 1; k <= cnt1; k++) {
        for (int l = cnt2 - j; l >= 0; l--) {
            if (l - p[k].first >= 0)
                f[k][l] =
                    max(f[k - 1][l], f[k - 1][l - p[k].first] + p[k].second);
        }
        DEBUG for (int l = 0; l <= cnt2 - j; l++) cout << f[k][l] << ' ';
        DEBUG cout << endl;
    }

    for (int k = j; k <= cnt2; k++) {
        for (int l = cnt2 - j; l >= 1; l--) {
            g[k][l] = max(g[k - 1][l], g[k - 1][l - 1] + q[k].second);
        }
        DEBUG for (int l = 0; l <= cnt2 - j; l++) cout << g[k][l] << ' ';
        DEBUG cout << endl;
    }

    int tt = 0;
    for (int l = 0; l <= cnt2 - j; l++) {
        DEBUG cout << "--" << g[cnt2][l + guagou] << " " << f[cnt1][l] << endl;
        tt = max(tt, g[cnt2][l + guagou] + f[cnt1][l]);
    }

    cout << ans + tt << endl;

    return 0;
}