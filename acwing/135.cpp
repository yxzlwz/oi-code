#include <bits/stdc++.h>
using namespace std;

const int N = 300001;

int n, m, a[N], s[N];
int q[N], l, r;

int main() {
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        ans = min(ans, a[i]);
    }
    int i = 1;
    l = 1, r = 1, q[1] = 0;
    while (i <= n) {
        while (l <= r && q[l] < i - m) l++;
        ans = max(ans, s[i] - s[q[l]]);
        while (l <= r && s[q[r]] >= s[i]) r--;
        q[++r] = i;
        i++;
    }
    cout << ans << endl;
}
