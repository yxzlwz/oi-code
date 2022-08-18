#include <cstring>
#include <iostream>

typedef long long ll;

const int N = 1000010;

ll n, m, c[N], a[N];
inline ll lowbit(ll i) { return i & (-i); }

ll getsum(ll x) {
    ll ans = 0;
    for (ll i = x; i > 0; i -= lowbit(i)) ans += c[i];
    return ans;
}

void update(ll i, ll k) {
    while (i <= n) {
        c[i] += k;
        i += lowbit(i);
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    memset(c, 0, sizeof(c));
    ll x;

    for (ll i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        update(i, a[i] - a[i - 1]);
    }
    while (m--) {
        ll k, a, b, c;
        scanf("%lld %lld", &k, &a);
        if (k == 1) {
            scanf("%lld %lld", &b, &c);
            ll x = getsum(a) - getsum(a - 1), y = getsum(b + 1) - getsum(b);
            update(a, c);
            update(b + 1, -c);
        } else
            printf("%lld\n", getsum(a));
    }
    return 0;
}
