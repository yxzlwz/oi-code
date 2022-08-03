#include <bits/stdc++.h>
using namespace std;
int c[10000001] = {0};
long long n, a[1000001] = {0}, s = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    int avg = s / n;

    for (int i = 1; i < n; i++) {
        c[i + 1] = c[i] + a[i] - avg;
    }
    c[1] = c[n] + a[n] - avg;

    sort(c + 1, c + n + 1);
    int p = (n + 1) >> 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(c[i] - c[p]);
    }
    cout << ans << endl;

    return 0;
}