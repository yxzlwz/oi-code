#include <bits/stdc++.h>
using namespace std;

int f[10001], c[10001], d[10001];
int cc[10001], dd[10001];
int g[10001];

int check(int x) {
    if (f[x] == x)
        return x;
    else
        return f[x] = check(f[x]);
}

int merge(int x, int y) { f[check(y)] = check(x); }

int main() {
    int n, m, w;
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        cin >> c[i] >> d[i];
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    for (int i = 1; i <= n; i++) {
        cc[check(i)] += c[i];
        dd[check(i)] += d[i];
    }

    for (int i = 1; i <= n; i++) {
        if (cc[i] == 0 && dd[i] == 0) continue;
        for (int j = w; j >= cc[i]; j--) g[j] = max(g[j], g[j - cc[i]] + dd[i]);
    }

    cout << g[w];
    return 0;
}

/*
5 3 10
3 10
3 10
3 10
5 100
10 1
1 3
3 2
4 2
*/