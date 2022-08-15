#include <bits/stdc++.h>
using namespace std;

int n, d, cnt;
double cur;

struct range {
    double l, r;
} b[1001];

bool cmp(range x, range y) { return x.r < y.r; }

int main() {
    cin >> n >> d;
    int x, y;
    double t;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        y = abs(y);
        if (y > d) {
            cout << -1 << endl;
            return 0;
        }
        t = sqrt(d * d - y * y);
        b[i].l = x - t;
        b[i].r = x + t;
    }

    sort(b + 1, b + n + 1, cmp);

    cnt = 1;
    cur = b[1].r;
    for (int i = 2; i <= n; i++) {
        if (cur < b[i].l) {
            cnt++;
            cur = b[i].r;
        }
    }
    cout << cnt;

    return 0;
}