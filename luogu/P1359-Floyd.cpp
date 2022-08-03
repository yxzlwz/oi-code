#include <bits/stdc++.h>
using namespace std;

int a[201][201];

int main() {
    memset(a, 0x7f7f7f7f, sizeof(a));
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> a[i][j];
            // a[j][i] = a[i][j];  // 有向图 这个万万不能加！
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || i == k || j == k) continue;
                if (a[i][k] + a[k][j] < a[i][j]) a[i][j] = a[i][k] + a[k][j];
            }
        }
    }

    cout << a[1][n];

    return 0;
}