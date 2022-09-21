#include <bits/stdc++.h>
using namespace std;

int a[1000001], cnt[2001];

int main() {
    int n, m;
    cin >> n >> m;
    int l = 1, r = 1, cntt = 0, ans = INT_MAX, x, y;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (r <= n) {
        if (!cnt[a[r]]) cntt++;
        cnt[a[r]]++;
        if (cntt < m) {
            r++;
            continue;
        }
        while (cnt[a[l]] > 1) cnt[a[l]]--, l++;
        if (r - l + 1 < ans) ans = r - l + 1, x = l, y = r;
        r++;
    }
    cout << x << ' ' << y << endl;
}