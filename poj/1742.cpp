#include <bits/stdc++.h>
using namespace std;

const int N = 101, M = 100001;

bool f[M];
int use[N], n, m, a[N], c[N];

int main() {
    cin >> n >> m;
    while (n || m) {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) {
            memset(use, 0, sizeof(use));
            f[0] = 1;
            for (int j = a[i]; j <= m; j++) {
                if (!f[j] && f[j - a[i]] && use[j - a[i]] + 1 <= c[i]) {
                    f[j] = 1;
                    use[j] = use[j - a[i]] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++)
            if (f[i]) ans++;
        cout << ans << endl;
        cin >> n >> m;
    }
}