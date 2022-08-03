#include <bits/stdc++.h>
using namespace std;

map<int, int> f;

int find(int a) {
    if (f[a] != a) {
        return f[a] = find(f[a]);
    } else {
        return a;
    }
}

int hb(int a, int b) { f[find(b)] = find(a); }

int main() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for (int i = -m; i <= n; i++) {
        if (i == 0) continue;
        f[i] = i;
    }
    f[-1] = f[1];

    int x, y;
    while (p--) {
        cin >> x >> y;
        hb(x, y);
    }
    while (q--) {
        cin >> x >> y;
        hb(x, y);
    }

    int girl = 0, boy = 0;
    for (int i = -m; i < 0; i++) {
        if (find(i) == 1) girl++;
    }
    for (int i = 1; i <= n; i++) {
        if (find(i) == 1) boy++;
    }

    cout << min(boy, girl);

    return 0;
}