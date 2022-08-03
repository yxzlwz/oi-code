#include <bits/stdc++.h>

typedef long long ll;
const int N = 1 << 13;
int n, m;
ll c[N][N];

inline ll lowbit(ll i) { return i & (-i); }

void update(ll x, ll y, ll k) {
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= m; j += lowbit(j)) c[i][j] += k;
}

ll getsum(ll x, ll y) {
    ll ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j)) ans += c[i][j];
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    ll opt, a, b, c, d;
    while (scanf("%lld", &opt) != EOF) {
        if (opt == 1) {
            scanf("%lld %lld %lld", &a, &b, &c);
            update(a, b, c);
        } else {
            scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
            printf("%lld\n", getsum(c, d) - getsum(a - 1, d) -
                                 getsum(c, b - 1) + getsum(a - 1, b - 1));
        }
    }

    return 0;
}
