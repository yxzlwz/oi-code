#include <bits/stdc++.h>
using namespace std;

double x[20], y[20], f[20][35000];
double dis(int a, int b) {
    return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf%lf", &x[i], &y[i]);
    memset(f, 127, sizeof(f));
    for (int s = 1; s <= (1 << n) - 1; s++)
        for (int i = 1; i <= n; i++) {
            if ((s & (1 << (i - 1))) == 0) continue;
            if (s == (1 << (i - 1))) {
                f[i][s] = 0;
                continue;
            }
            for (int j = 1; j <= n; j++) {
                if ((s & (1 << (j - 1))) == 0 || i == j) continue;
                f[i][s] = min(f[i][s], f[j][s - (1 << (i - 1))] + dis(i, j));
            }
        }
    double ans = -1;
    for (int i = 1; i <= n; i++) {
        double s = f[i][(1 << n) - 1] + dis(i, 0);
        if (ans == -1 || ans > s) ans = s;
    }
    printf("%.2lf\n", ans);
    return 0;
}