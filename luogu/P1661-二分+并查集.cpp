#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, a[N][2], m[N][N];

class bcj {
   public:
    int f[N];
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
};

bool check(int mid) {
    bcj b;
    b.init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (m[i][j] <= mid) b.merge(i, j);
    int f = b.find(1);
    for (int i = 2; i <= n; i++)
        if (b.find(i) != f) return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            m[i][j] = m[j][i] = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
        }
    }

    int l = 0, r = 1e9 + 5, mid;
    while (l <= r) {
        mid = l + r >> 1;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << int(l + 1) / 2 << endl;

    return 0;
}