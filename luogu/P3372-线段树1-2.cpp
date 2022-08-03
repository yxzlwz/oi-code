#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100001;

struct Node {
    int l, r, sum, tag;
} tree[4 * N];

void build(int rt, int l, int r) {
    tree[rt].l = l, tree[rt].r = r;
    if (l == r) {
        int t;
        cin >> t;
        tree[rt].sum = t;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

void change(int rt, int x, int v) {
    if (tree[rt].l == tree[rt].r) {
        tree[rt].sum += v;
        return;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (x <= mid)
        change(rt << 1, x, v);
    else
        change(rt << 1 | 1, x, v);
}

void pushdown(int rt) {
    if (tree[rt].tag == 0) return;
    tree[rt << 1].tag += tree[rt].tag;
    tree[rt << 1 | 1].tag += tree[rt].tag;
    tree[rt << 1].sum += tree[rt].tag * (tree[rt << 1].r - tree[rt << 1].l + 1);
    tree[rt << 1 | 1].sum +=
        tree[rt].tag * (tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1);
    tree[rt].tag = 0;
}

int query(int rt, int l, int r) {
    if (l <= tree[rt].l && tree[rt].r <= r) return tree[rt].sum;
    int mid = (tree[rt].l + tree[rt].r) >> 1, res = 0;
    pushdown(rt);
    if (l <= mid) res += query(rt << 1, l, r);
    if (mid < r) res += query(rt << 1 | 1, l, r);
    return res;
}

void update(int rt, int l, int r, int x) {
    if (l <= tree[rt].l && tree[rt].r <= r) {
        tree[rt].tag += x;
        tree[rt].sum += x * (tree[rt].r - tree[rt].l + 1);
        return;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    pushdown(rt);
    if (l <= mid) update(rt << 1, l, r, x);
    if (mid < r) update(rt << 1 | 1, l, r, x);
    tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

signed main() {
    int n, m;
    cin >> n >> m;
    build(1, 1, n);
    while (m--) {
        int o, a, b, c;
        cin >> o >> a >> b;
        if (o == 1) {
            cin >> c;
            update(1, a, b, c);
        } else if (o == 2) {
            cout << query(1, a, b) << endl;
        }
    }
}
