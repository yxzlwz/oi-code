#include <bits/stdc++.h>
using namespace std;

int n, a[55][2], len, ans, cnt;

class bcj {
   public:
    int f[50000];
    void init() {
        for (int i = 1; i <= n; i++) f[i] = i;
    }
    void merge(int x, int y) {
        int p = find(x), q = find(y);
        if (p == q) return;
        f[p] = q;
    }
    int find(int x) {
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
} b;

struct edges {
    int x, y, v;
} e[50005];

bool cmp(edges a, edges b) { return a.v < b.v; }

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            len++;
            e[len].x = i;
            e[len].y = j;
            e[len].v = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
        }
    }

    sort(e + 1, e + len + 1, cmp);

    b.init();
    for (int i = 1; i <= len && cnt < n; i++) {
        if (b.find(e[i].x) != b.find(e[i].y)) {
            b.merge(e[i].x, e[i].y);
            ans = e[i].v;
            cnt++;
        }
    }

    cout << (ans + 1) / 2 << endl;

    return 0;
}