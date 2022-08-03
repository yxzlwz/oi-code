#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100001][2];
int l = 1, r = INT_MAX / 2, mid, ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0];
        a[i][1] = a[i - 1][1] + a[i][0];
    }
    while (l <= r) {
        mid = l + r >> 1;
        int cnt = 1, last = 0, s = 0;
        for (int i = 1; i <= n; i++) {
            if(a[i][0] > mid) {
                cnt = n;
                break;
            }
            if (a[i][1] - a[last][1] > mid) {
                cnt++;
                last = i - 1;
            }
        }
        if (cnt > m)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l << endl;

    return 0;
}