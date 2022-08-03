#include <bits/stdc++.h>
using namespace std;
int a[500001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int x = a[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - x);
    }
    cout << ans << endl;
}