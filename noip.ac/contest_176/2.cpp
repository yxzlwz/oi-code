#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

const int mod = 100000007;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 3 && n % 4) {
            cout << -1 << endl;
            continue;
        }
        if (n % 3 == 0) {
            cout << ((n / 3 % mod) * (n / 3 % mod) % mod) * (n / 3 % mod) % mod
                 << endl;
            continue;
        }
        if (n % 4 == 0) {
            cout << ((n / 2 % mod) * (n / 4 % mod) % mod) * (n / 4 % mod) % mod
                 << endl;
        }
    }
}