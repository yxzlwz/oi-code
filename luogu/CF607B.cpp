#include <bits/stdc++.h>
using namespace std;

const int N = 501;

int n, a[N], f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(f, 0x3f3f3f3f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 1;

    for (int l = 1; l < n; l++) {
        if (a[l] == a[l + 1])
            f[l][l + 1] = 1;
        else
            f[l][l + 1] = 2;
    }
    for (int x = 3; x <= n; x++) {
        for (int l = 1; l + x - 1 <= n; l++) {
            int r = l + x - 1;
            if (a[l] == a[r]) f[l][r] = f[l + 1][r - 1];
            for (int k = l; k < r; k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
            }
        }
    }

    cout << f[1][n] << endl;
}
