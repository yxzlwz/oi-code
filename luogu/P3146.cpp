#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int f[N][N], a[N], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][i] = a[i];
    }
    int ans = 0;
    for (int x = 2; x <= n; x++) {
        for (int l = 1; l + x - 1 <= n; l++) {
            int r = l + x - 1;
            for (int k = l; k < r; k++) {
                if (f[l][k] == f[k + 1][r]) {
                    f[l][r] = max(f[l][r], f[l][k] + 1);
                    ans = max(ans, f[l][r]);
                }
            }
        }
    }
    cout << ans;
}
