#include <cstring>
#include <iostream>

typedef long long ll;

ll n, m, c[2][500001];
inline ll lowbit(ll i) { return i & (-i); }

ll getsum(ll x, ll *c) {
    ll ans = 0;
    for (ll i = x; i > 0; i -= lowbit(i)) ans += c[i];
    return ans;
}

void update(ll i, ll k, ll *c) {
    while (i <= n) {
        c[i] += k;
        i += lowbit(i);
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    while (m--) {
        ll k, a, b;
        scanf("%lld %lld", &k, &a);
        if (k == 1) {
            scanf("%lld", &b);
            update(a, 1, c[0]);
            update(b, 1, c[1]);
        } else {
            printf("%d\n", bool((getsum(a, c[0]) - getsum(a - 1, c[1])) % 2));
        }
    }
    return 0;
}
