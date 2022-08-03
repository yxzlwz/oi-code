#include <bits/stdc++.h>
using namespace std;

pair<int, int> x[501];

int f[1001][1001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i].first;
        x[i + n].first = x[i].first;
    }
    for (int i = 1; i <= n * 2 - 1; i++) x[i].second = x[i + 1].first;
    x[n * 2].second = x[1].first;
    for (int t = 1; t <= n; t++) {
        for (int i = 1; i <= n * 2 - t; i++) {
            int j = i + t - 1;
            for (int k = i; k <= j - 1; k++) {
                f[i][j] =
                    max(f[i][j], f[i][k] + f[k + 1][j] +
                                     x[i].first * x[k].second * x[j].second);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i][i + n - 1]);
    cout << ans;
}