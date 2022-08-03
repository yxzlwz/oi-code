#include <bits/stdc++.h>
using namespace std;

const int N = 501;

int dpmin[N][N], dpmax[N][N], n, a[N << 1], s[N << 1];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        a[i + n] = a[i];
        s[i + n] = s[i + n - 1] + a[i];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j + i <= n * 2; j++) {
            int r = i + j - 1;
            dpmin[j][r] = 0x3f3f3f3f;
            dpmax[j][r] = -0x3f3f3f3f;
            for (int k = j; k < r; k++) {
                dpmin[j][r] = min(dpmin[j][r], dpmin[j][k] + dpmin[k + 1][r] +
                                                   s[r] - s[j - 1]);
                dpmax[j][r] = max(dpmax[j][r], dpmax[j][k] + dpmax[k + 1][r] +
                                                   s[r] - s[j - 1]);
            }
        }
    }
    int maxx = -0x3f3f3f3f, minn = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        minn = min(minn, dpmin[i][i + n - 1]);
        maxx = max(maxx, dpmax[i][i + n - 1]);
    }
    cout << minn << endl << maxx;
    return 0;
}