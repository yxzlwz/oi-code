#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

struct node {
    int x, l, r;
} s[N];

int n, m, cnt, where[N];

int main() {
    s[++cnt] = (node){1, -1, -1};
    where[1] = 1;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int k, p;
        scanf("%d %d", &k, &p);
        if (p == 0) {
            s[++cnt] = (node){i, s[k].l, k};
            s[s[k].l].r = cnt;
            s[k].l = cnt;
            where[i] = cnt;
        } else {
            s[++cnt] = (node){i, k, s[k].r};
            s[s[k].r].l = cnt;
            s[k].r = cnt;
            where[i] = cnt;
        }
    }
    scanf("%d", &m);
    while (m--) {
        int t;
        cin >> t;
        int l = where[t];
        if (l == -1) continue;
        s[s[l].l].r = s[l].r;
        s[s[l].r].l = s[l].l;
        where[t] = -1;
    }
    int l = 0;
    for (int i = 1; i <= cnt; i++) {
        if (s[i].l == -1) {
            l = i;
            break;
        }
    }
    while (s[l].r != -1) {
        printf("%d ", s[l].x);
        l = s[l].r;
    };
    printf("%d\n", s[l].x);
    return 0;
}