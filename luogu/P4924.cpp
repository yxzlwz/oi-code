#include <bits/stdc++.h>
using namespace std;

int a[501][501], b[501][501];
int c[50001];

int main() {
    int n, m, x, y, r, z;
    cin >> n >> m;

    int tot = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) a[i][j] = ++tot;

    while (m--) {
        cin >> x >> y >> r >> z;
        tot = 0;
        for (int i = x - r; i <= x + r; i++) {
            for (int j = y - r; j <= y + r; j++) {
                c[tot++] = a[i][j];
            }
        }
        tot = 0;
        if (z == 0) {
            for (int j = y + r; j >= y - r; j--) {
                for (int i = x - r; i <= x + r; i++) {
                    a[i][j] = c[tot++];
                }
            }
        } else {
            for (int j = y - r; j <= y + r; j++) {
                for (int i = x + r; i >= x - r; i--) {
                    a[i][j] = c[tot++];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << a[i][n] << endl;
    }

    return 0;
}