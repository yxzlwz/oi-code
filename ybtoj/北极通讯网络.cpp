#include <bits/stdc++.h>
using namespace std;

int n, k, m[501][2];

struct Edge {
    double f, t, w;
} edge[250000], edges[501];
int cnt;
bool cmp(Edge a, Edge b) { return a.w < b.w; }

class bcj {
   public:
    int f[250000];
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }
    }
    int find(int x) {
        while (f[x] != x) {
            f[x] = f[f[x]];
            x = f[x];
        }
        return x;
    }
    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            f[fx] = fy;
        }
    }
};

int main() {
    // cin >> n >> k;
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m[i][0] >> m[i][1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edge[++cnt].f = i;
            edge[cnt].t = j;
            edge[cnt].w =
                sqrt(pow(m[i][0] - m[j][0], 2) + pow(m[i][1] - m[j][1], 2));
        }
    }
    sort(edge + 1, edge + cnt + 1, cmp);
    bcj b;
    b.init(n);
    int cntt = 0;
    for (int i = 1; i <= cnt && cntt < n; i++) {
        if (b.find(edge[i].f) != b.find(edge[i].t)) {
            b.merge(edge[i].f, edge[i].t);
            edges[cntt++] = edge[i];
        }
    }
    if (k <= 1) {
        printf("%.2f\n", edges[cntt - 1].w);
    } else {
        printf("%.2f\n", edges[cntt - k].w);
    }
    return 0;
}
