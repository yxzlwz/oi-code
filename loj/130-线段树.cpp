#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1000001, M = 1000001;

ll n, m, k, a, b;

class XDS {
   private:
    ll tree[N << 2];

   public:
    void init() {
        for (int i = 0; i < (N << 2); i++) tree[i] = 0;
    }
    void plus(ll x, ll l, ll r) {
        if (a < l || a > r) return;
        if (a == l && a == r) {
            tree[x] += b;
            return;
        }
        ll mid = (l + r) >> 1;
        if (a <= mid)
            plus(x * 2, l, mid);
        else
            plus(x * 2 + 1, mid + 1, r);
        tree[x] = tree[x * 2] + tree[x * 2 + 1];
    }
    ll sum(ll x, ll l, ll r) {
        if (a <= l && r <= b) return tree[x];
        ll mid = (l + r) >> 1, ans = 0;
        if (a <= mid) ans += sum(x * 2, l, mid);
        if (b > mid) ans += sum(x * 2 + 1, mid + 1, r);
        return ans;
    }
} xds;

int main() {
    xds.init();
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        a = i;
        scanf("%lld", &b);
        xds.plus(1, 1, n);
    }
    while (m--) {
        scanf("%lld %lld %lld", &k, &a, &b);
        if (k == 2)
            printf("%lld\n", xds.sum(1, 1, n));
        else
            xds.plus(1, 1, n);
    }
    return 0;
}
