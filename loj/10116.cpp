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
    while (m--) {
        char k;
        ll a, b;
        scanf(" %c %lld", &k, &a);
        if (k == 'B') {
            scanf("%lld", &b);
            update(a, b);
        } else if (k == 'C') {
            scanf("%lld", &b);
            update(a, -b);
        } else
            printf("%lld\n", getsum(a));
    }
    return 0;
}
