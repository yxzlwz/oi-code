#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1000001;

class XDS {
   private:
    ll lazy[N << 2], minn[N << 2];

   public:
    void init() {
        memset(lazy, 0, sizeof(lazy));
        memset(minn, 0, sizeof(minn));
    }
    void build(int x, int l, int r) {
        if (l == r) {
            scanf("%lld", &minn[x]);
            return;
        }
        int mid = (l + r) >> 1;
        build(x * 2, l, mid);
        build(x * 2 + 1, mid + 1, r);
        minn[x] = min(minn[x * 2], minn[x * 2 + 1]);
    }
    void add(int x, int l, int r, ll v) {
        lazy[x] += v;
        minn[x] += v;
        // sum[x] += (r - l + 1) * v;
    }
    void pushdown(int x, int l, int r) {
        if (lazy[x]) {
            add(x * 2, l, (l + r) >> 1, lazy[x]);
            add(x * 2 + 1, ((l + r) >> 1) + 1, r, lazy[x]);
            lazy[x] = 0;
        }
    }
    void update(int x, int l, int r, int a, int b, ll v) {
        if (a > r || b < l) return;
        if (a <= l && r <= b) {
            add(x, l, r, v);
            return;
        }
        pushdown(x, l, r);
        int mid = (l + r) >> 1;
        update(x * 2, l, mid, a, b, v);
        update(x * 2 + 1, mid + 1, r, a, b, v);
        minn[x] = min(minn[x * 2], minn[x * 2 + 1]);
    }
    ll query(int x, int l, int r, int a, int b) {
        if (a > r || b < l) return 0;
        if (a <= l && r <= b) return minn[x];
        pushdown(x, l, r);
        int mid = (l + r) >> 1;
        return min(query(x * 2, l, mid, a, b),
                   query(x * 2 + 1, mid + 1, r, a, b));
    }
} xds;

int main() {
    int n, m;
    cin >> n >> m;
    xds.init();
    xds.build(1, 1, n);
    while (m--) {
        int d, s, t;
        cin >> d >> s >> t;
        
    }