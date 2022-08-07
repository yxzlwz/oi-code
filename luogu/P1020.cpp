#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int a[N], n, h[N], dd[N >> 1], cnt;

int main() {
    freopen("P1020.in", "r", stdin);
    int t;
    while (cin >> t) a[++n] = t;
    int len = 0;
    h[0] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (h[mid] >= a[i])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, l + 1);
        h[l + 1] = a[i];
    }
    cout << len << endl;

    dd[++cnt] = a[1];
    for (int i = 2; i <= n; i++) {
        int num = -1, val = -1;
        for (int j = 1; j <= cnt; ++j) {
            if (dd[j] >= a[i] && (val == -1 || val > dd[j])) {
                val = dd[j];
                num = j;
            }
        }
        if (num == -1)
            dd[++cnt] = a[i];
        else
            dd[num] = a[i];
    }
    cout << cnt << endl;
    return 0;
}