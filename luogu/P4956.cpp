#include <bits/stdc++.h>
using namespace std;

int n;

inline int money(int x, int k) { return (x * 7 + k * 21) * 52; }

int main() {
    cin >> n;
    int nn = n / 7 / 52;
    for (int k = 1; true; k++) {
        for (int x = 1; x <= 100; x++) {
            if (money(x, k) == n) {
                cout << x << endl << k << endl;
                return 0;
            }
        }
    }
    return 0;
}
