#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, LogN = 19;

int n, k, logg[N], dp[N][LogN + 5];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &dp[i][0]);
    logg[0] = -1;
    for (int i = 1; i <= n; i++) logg[i] = logg[i >> 1] + 1;
    for (int j = 1; j <= LogN; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (k--) {
        int x, y;
        scanf("%d %d", &x, &y);
        int tt = logg[y - x + 1];
        printf("%d\n", max(dp[x][tt], dp[y - (1 << tt) + 1][tt]));
    }
    return 0;
}