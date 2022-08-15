#include <bits/stdc++.h>
using namespace std;

int ss[10001], ss_cnt;
bool bsss[100001];  // 不是素数
int a1c[10001], b1c[10001];

void qss(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!bsss[i]) ss[++ss_cnt] = i;
        for (int j = 1; j <= ss_cnt && ss[j] <= n / i; ++j) {
            bsss[i * ss[j]] = true;
            if (i % ss[j] == 0) break;
        }
    }
}

void fj(int x, int *c) {
    int sqrt_x = sqrt(x) + 1;
    for (int i = 1; i <= ss_cnt && ss[i] < sqrt_x; i++) {
        while (x % ss[i] == 0) {
            x /= ss[i];
            c[i]++;
        }
    }
}

int main() {
    int T;
    cin >> T;
    qss(100001);
    while (T--) {
        int a0, a1, b0, b1;
        cin >> a0 >> a1 >> b0 >> b1;
        if (a0 < a1 || b1 < b0 || a1 > b1) {
            puts("0\n");
            continue;
        }
        fj(a1, a1c);
        fj(b1, b1c);
        int ans = 1;
        for (int i = 1; i <= ss_cnt; i++) {
            if (a1c[i] == 0 && b1c[i] == 0) continue;
            ans *= (b1c[i] - a1c[i]);
        }
        cout << ans << endl;
    }
}
