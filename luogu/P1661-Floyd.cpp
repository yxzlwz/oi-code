#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, x[N], y[N], d[N][N], ans;

int main() {
    memset(d, 1e9, sizeof(d));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            d[i][j] = d[j][i] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || i == k || j == k) continue;
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans = max(ans, d[i][j]);
        }
    }

    cout << int(ans + 1) / 2 << endl;

    return 0;
}