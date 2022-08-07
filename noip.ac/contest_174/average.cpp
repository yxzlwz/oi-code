#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m, k;
class XDS1 {
   private:
    int a[N << 2];

   public:
    void build(int x, int l, int r) {
        if (l == r) {
            cin >> a[x];
            return;
        }
        int mid = (l + r) >> 1;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        a[x] = max(a[x << 1], a[x << 1 | 1]);
        return;
    }
    int query(int x, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return a[x];
        int mid = (l + r) >> 1;
        int ans = INT_MIN;
        if (ql <= mid) ans = max(ans, query(x << 1, l, mid, ql, qr));
        if (qr >= mid) ans = max(ans, query(x << 1 | 1, mid + 1, r, ql, qr));
        return ans;
    }
    void update(int x, int l, int r, int u, int v) {
        if (l > u || r < u) return;
        if (l == u && r == u) {
            a[x] = v;
            return;
        }
        int mid = (l + r) >> 1;
        update(x << 1, l, mid, u, v);
        update(x << 1 | 1, mid + 1, r, u, v);
        a[x] = max(a[x << 1], a[x << 1 | 1]);
        return;
    }
} xds1;

int main() {
    freopen("average.in", "r", stdin);
    freopen("average.out", "w", stdout);
    cin >> n >> k >> m;
    if (k == 1) {
        xds1.build(1, 1, n);
        cout << xds1.query(1, 1, n, 1, n) << endl;
        while (m--) {
            int x, y;
            cin >> x >> y;
            xds1.update(1, 1, n, x, y);
            cout << xds1.query(1, 1, n, 1, n) << endl;
        }
        return 0;
    }
}