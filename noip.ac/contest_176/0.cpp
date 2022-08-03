#include <bits/stdc++.h>
using namespace std;

const int N = 10001;

int n, m, a[N], b[N];

int dis(int x) {
    int l = 1, r = m;
    while (b[l + 1] < a[x] && l + 1 <= m) ++l;
    while (b[r - 1] > a[x] && r - 1 >= 0) --r;
    return min(abs(b[l] - a[x]), abs(b[r] - a[x]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dis(i));
    cout << ans << endl;
}
