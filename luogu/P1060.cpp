#include <bits/stdc++.h>
using namespace std;
int v[30], p[30];
int f[50000];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> p[i] >> v[i];
    }

    for (int i = 0; i < m; i++) {
        for (int j = n; j > 0; j--) {
            if (j > p[i])
                f[j] = max(f[j], f[j - p[i]] + p[i] * v[i]);
            else
                break;
        }
    }

    cout << f[n];

    return 0;
}