#include <bits/stdc++.h>
using namespace std;

int v[50], n, m;
int f[20001];

int main() {
    // memset(f, -1, sizeof(f));
    f[0] = 0;
    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        for (int j = m; j ; j--) {
            if (v[i] <= j) {
                if (f[j - v[i]] + v[i] > f[j]) f[j] = f[j - v[i]] + v[i];
            }
        }
    }

    cout << m - f[m];
}