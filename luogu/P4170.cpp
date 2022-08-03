#include <bits/stdc++.h>
using namespace std;

const int N = 51;

string s;
int n, f[N][N];

int main() {
    cin >> s;

    n = s.length();
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 1;

    for (int x = 2; x <= n; x++) {
        for (int l = 1; l + x - 1 <= n; l++) {
            int r = l + x - 1;
            if (s[l - 1] == s[r - 1])
                f[l][r] = min(f[l][r - 1], f[l + 1][r]);
            else {
                for (int k = l; k < r; k++)
                    f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
            }
        }
    }

    cout << f[1][n];

    return 0;
}
