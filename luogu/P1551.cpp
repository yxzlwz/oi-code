// https://www.luogu.com.cn/problem/P3367

#include <bits/stdc++.h>
using namespace std;

int f[10001];

int find(int a) {
    if (f[a] != a) {
        // 路径压缩：一棵深度大的树变成宽度大的树，减少递归
        return f[a] = find(f[a]);
    } else {
        return a;
    }
}

int hb(int a, int b) { f[find(b)] = find(a); }

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) f[i] = i;

    int x, y;
    while (m--) {
        cin >> x >> y;
        hb(x, y);
    }
    while (p--) {
        cin >> x >> y;
        if (find(x) == find(y))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}