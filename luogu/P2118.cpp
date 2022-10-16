#include <bits/stdc++.h>
using namespace std;
signed main() {
    int a, b, l;
    cin >> a >> b >> l;
    double c = double(a) / double(b);
    int m = l, n = 1;
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            if (double(i) / double(j) >= c &&
                double(i) / double(j) - c < double(m) / double(n) - c) {
                m = i, n = j;
            }
        }
    }
    cout << m << " " << n;
}