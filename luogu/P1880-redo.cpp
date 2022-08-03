#include <bits/stdc++.h>
using namespace std;

const int N = 501;

int dpmin[N][N], dpmax[N][N], a[N], s[N], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        a[i + n] = a[i];
        s[i + n] = s[i + n - 1] + a[i + n];
    }

    for (int x = 2; x <= n; x++) {
        for (int l = 1; l + x - 1 < n * 2; l++) {
            int r = l + x - 1;  // 为什么-1：保证区间[l, r]长度为n
            dpmax[l][r] = -99999999;
            dpmin[l][r] = 99999999;
            for (int k = l; k < r; k++) {
                // 为什么k的范围左闭右开：我们计算的后半段是k+1~r
                dpmax[l][r] = max(dpmax[l][r], dpmax[l][k] + dpmax[k + 1][r] +
                                                   s[r] - s[l - 1]);
                dpmin[l][r] = min(dpmin[l][r], dpmin[l][k] + dpmin[k + 1][r] +
                                                   s[r] - s[l - 1]);
            }
        }
    }

    int minn = 99999999, maxx = -99999999;
    for (int i = 1; i <= n; i++) {
        minn = min(minn, dpmin[i][i + n - 1]);
        maxx = max(maxx, dpmax[i][i + n - 1]);
    }
    cout << minn << endl << maxx;
}
