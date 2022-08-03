#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 15;
int n, s[N], e[N], d[N], T;

int S(int x) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] <= x) ans += (min(x, e[i]) - s[i]) / d[i] + 1;
    }
    return ans;
}

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &s[i], &e[i], &d[i]);
    }
    if (S(INT_MAX) % 2 == 0) {
        cout << "There's no weakness." << endl;
        return;
    }
    int l = 0, r = INT_MAX;
    while (l < r) {
        int mid = (long long)(l + r) >> 1;
        if (S(mid) & 1)
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d %d\n", l, S(l) - S(l - 1));
}

int main() {
    cin >> T;
    while (T--) work();
    return 0;
}