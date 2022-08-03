#include <bits/stdc++.h>
using namespace std;

const int G = 101;

int d, g, f[G][G];

struct GARBAGE {
    int t, f, h;
} a[G];

bool cmp(const GARBAGE &a, const GARBAGE &b) { return a.t < b.t; }

int main() {
    cin >> d >> g;
    for (int i = 1; i <= g; i++) cin >> a[i].t >> a[i].f >> a[i].h;
    sort(a + 1, a + g + 1, cmp);
    f[0][0] = 10;
    for (int i = 1; i <= g; i++) {
        for (int j = 0; j <= d; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i].t)
                f[i][j] = max(f[i][j], f[i - 1][j - a[i].t] + a[i].f);
        }
    }
}
