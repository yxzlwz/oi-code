#include <bits/stdc++.h>
using namespace std;

int f[1000001];

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
    for (int i = 1; i <= n + m; i++) {
        f[i] = i;
    }
    f[n + 1] = f[1];

    int x, y;
    while (p--) {
        cin >> x >> y;
        hb(x, y);
    }
    while (q--) {
        cin >> x >> y;
        hb(-x + n, -y + n);
    }

    int girl = 0, boy = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == find(1)) boy++;
    }
    for (int i = n + 1; i <= n + m; i++) {
        if (find(i) == find(1)) girl++;
    }

    cout << min(boy, girl);
    

    return 0;
}