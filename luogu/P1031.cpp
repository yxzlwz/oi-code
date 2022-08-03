#include <bits/stdc++.h>
using namespace std;

int n, tot, ave, cnt;

struct node {
    int val;
    int left_tot;
} a[101];

bool check() {
    for (int i = 1; i <= n; i++)
        if (a[i].val != ave) return 0;
    return 1;
}

int main() {
    a[0].val = a[0].left_tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        tot += a[i].val;
        a[i].left_tot = a[i - 1].left_tot + a[i].val;
    }
    ave = tot / n;

    while (!check()) {
        for (int i = 1; i <= n; i++) {
            if (a[i].val > ave) {
                if (a[i - 1].left_tot < (i - 1) * ave) {
                    a[i - 1].val += min(abs(a[i].val - ave),
                                        (i - 1) * ave - a[i - 1].left_tot);
                    a[i - 1].left_tot += min(abs(a[i].val - ave),
                                             (i - 1) * ave - a[i - 1].left_tot);
                    a[i].val -= min(abs(a[i].val - ave),
                                    (i - 1) * ave - a[i - 1].left_tot);
                } else {
                    a[i + 1].val += abs(a[i].val - ave);
                    a[i].val -= abs(a[i].val - ave);
                    a[i + 1].left_tot -= abs(a[i].val - ave);
                }
                cnt++;
                // cout << cnt << "  ";
                // for (int i = 1; i <= n; i++) cout << a[i].val << " ";
                // cout << endl;
            }
        }
    }

    cout << cnt;

    return 0;
}