#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n, a[N];

int ltr[N], rtl[N], ltr_len, rtl_len, h[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = ltr_len;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (h[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        ltr_len = max(ltr_len, l + 1);
        h[l + 1] = a[i];
        ltr[i] = ltr_len;
    }
    memset(h, 0, sizeof(h));
    for (int i = n; i; --i) {
        int l = 0, r = rtl_len;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (h[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        rtl_len = max(rtl_len, l + 1);
        h[l + 1] = a[i];
        rtl[i] = rtl_len;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, ltr[i] + rtl[i] - 1);
    }
    cout << n - ans;
}