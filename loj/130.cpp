#include <cstring>
#include <iostream>

typedef long long ll;

ll n, m, c[1000010];
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
        scanf("%lld", &x);
        update(i, x);
    }
    while (m--) {
        ll k, a, b;
        scanf("%lld %lld %lld", &k, &a, &b);
        if (k == 1)
            update(a, b);
        else
            printf("%lld\n", getsum(b) - getsum(a - 1));
    }
    return 0;
}
