#include <bits/stdc++.h>
using namespace std;

int a[50001], n, ans[50001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, t = 0;
        cin >> x >> y;
        for (int j = 0; j <= x; j++) t += a[j];
        a[x]++;
        ans[t]++;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << endl;
}
