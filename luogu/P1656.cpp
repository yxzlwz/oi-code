#include <bits/stdc++.h>
using namespace std;

struct road {
    int a, b;
} p[6000];

int f[10001];

bool cmp(road x, road y) {
    if (x.a != y.a)
        return x.a < y.a;
    else
        return x.b < y.b;
}

void init() {
    for (int i = 0; i < 10000; i++) f[i] = i;
}

int check(int x) {
    if (f[x] != x)
        return f[x] = check(f[x]);
    else
        return f[x];
}

void merge(int x, int y) { f[check(y)] = check(x); }

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> p[i].a >> p[i].b;
    }
    sort(p, p + m, cmp);
    for (int i = 0; i < m; i++) {
        init();
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            merge(p[j].a, p[j].b);
            check(p[j].a);
            check(p[j].b);
        }
        int t = check(1);
        for (int j = 2; j <= n; j++) {
            if (check(j) != t) {
                cout << min(p[i].a, p[i].b) << " " << max(p[i].a, p[i].b)
                     << endl;
                break;
            }
        }
    }

    return 0;
}

/*
6 6
1 2
2 3
2 4
3 5
4 5
5 6
*/