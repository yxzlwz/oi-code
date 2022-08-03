#include <bits/stdc++.h>
using namespace std;

bool g[23][23];
long long f[21][21];
int plu[2][8] = {{2, 2, -2, -2, 1, 1, -1, -1}, {1, -1, 1, -1, 2, -2, 2, -2}};

int main() {
    int n, m, cx, cy;
    cin >> n >> m >> cx >> cy;

    g[cx][cy] = 1;

    for (int i = 0; i < 8; i++) {
        if ((cx + plu[0][i]) <= n && cy + plu[1][i] <= m)
            g[cx + plu[0][i]][cy + plu[1][i]] = 1;
    }

    f[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        if (!g[i][0])
            f[i][0] = f[i - 1][0];
        else
            f[i][0] = 0;
    }

    for (int i = 1; i <= m; i++) {
        if (!g[0][i])
            f[0][i] = f[0][i - 1];
        else
            f[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!g[i][j])
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            else
                f[i][j] = 0;
        }
    }

    cout << f[n][m];

    return 0;
}
