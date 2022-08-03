#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int z = x * y, cnt = 0;
    for (int i = 1; i <= y; i++) {
        int j = z / i;
        if (i * j == z && __gcd(i, j) == x) {
            cnt++;
            // cout << i << " " << j << endl;
        }
    }
    cout << cnt;
    return 0;
}