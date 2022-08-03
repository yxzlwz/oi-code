#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int g[N][2], ecnt, n, k;

struct node {
    int u, v;
    double w;
} edge[N * N];

class BCJ {
   private:
    int f[N];

   public:
    void init() {
        for (int i = 0; i < N; i++) f[i] = i;
    }
    int find(int x) {
        if (f[x] != x) f[x] = find(f[x]);
        return f[x];
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        f[x] = y;
    }
} bcj;

bool cmp(const node &a, const node &b) { return a.w < b.w; }

int main() {
    cin >> n >> k;
    if (n == k) {
        cout << "0.00\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) cin >> g[i][0] >> g[i][1];

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            edge[++ecnt] = (node){i, j,
                                  sqrt(pow(double(g[i][0] - g[j][0]), 2) +
                                       pow(double(g[i][1] - g[j][1]), 2))};
        }
    }
    sort(edge + 1, edge + ecnt + 1, cmp);
    int cnt = 0, i;
    bcj.init();
    for (i = 1; i <= ecnt; i++) {
        int u = edge[i].u, v = edge[i].v;
        if (bcj.find(u) != bcj.find(v)) {
            cnt++;
            bcj.merge(u, v);
        }
        if (cnt == n - k) {
            while (bcj.find(u) == bcj.find(v)) {
                i++;
                if (i == ecnt + 1) {
                    cout << "0.00\n";
                    return 0;
                }
                u = edge[i].u, v = edge[i].v;
            }
            cout << fixed << setprecision(2) << edge[i].w << endl;
            return 0;
        }
    }
}
