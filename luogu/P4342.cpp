#include <bits/stdc++.h>
using namespace std;

const int N = 501;

int dpmin[N][N], dpmax[N][N], a[N], s[N], n, opt[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> opt[i] >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        a[i + n] = a[i];
        opt[i + n] = opt[i];
        s[i + n] = s[i + n - 1] + a[i + n];
    }

    for (int x = 2; x <= n; x++) {
        for (int l = 1; l + x - 1 < n * 2; l++) {
            int r = l + x - 1;
            dpmax[l][r] = -99999999;
            dpmin[l][r] = 99999999;
            for (int k = l; k < r; k++) {
                if (opt[k] == 't') {
                    dpmax[l][r] =
                        max(dpmax[l][r],
                            dpmax[l][k] + dpmax[k + 1][r] + s[r] - s[l - 1]);
                    dpmin[l][r] =
                        min(dpmin[l][r],
                            dpmin[l][k] + dpmin[k + 1][r] + s[r] - s[l - 1]);
                } else {
                    dpmax[l][r] =
                        max(dpmax[l][r],
                            dpmax[l][k] + dpmax[k + 1][r] + s[r] - s[l - 1]);
                    dpmin[l][r] =
                        min(dpmin[l][r],
                            dpmin[l][k] + dpmin[k + 1][r] + s[r] - s[l - 1]);
                }
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
