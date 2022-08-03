#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 100001, M = 500001;

ll n, m, k, a, b;

class XDS {
   private:
    ll tree[N << 2];

   public:
    void plus(ll x, ll l, ll r) {
        if (a < l || a > r) return;
        if (a == l && a == r) {
            tree[x] += b;
            return;
        }
        ll mid = (l + r) >> 1;
        if (a <= mid) plus(x * 2, l, mid);
        else plus(x * 2 + 1, mid + 1, r);
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
    scanf("%lld %lld", &n, &m);
    while (m--) {
        scanf("%lld %lld %lld", &k, &a, &b);
        if (k)
            printf("%lld\n", xds.sum(1, 1, n));
        else
            xds.plus(1, 1, n);
    }
    return 0;
}
