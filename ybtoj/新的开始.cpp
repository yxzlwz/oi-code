#include <bits/stdc++.h>
using namespace std;

const int N = 301;

class BCJ {
   private:
    int f[N];

   public:
    void init() {
        for (int i = 1; i <= N; i++) f[i] = i;
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x];
        }
        return x;
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        f[y] = x;
    }
} bcj;

int n, v[N], p[N][N], es;

struct EDGE {
    int from, to, w;
} edge[N * N * N];

bool cmp(EDGE x, EDGE y) { return x.w < y.w; }

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        edge[++es].from = i;
        edge[es].to = 0;
        edge[es].w = v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> p[i][j];
            edge[++es].from = i;
            edge[es].to = j;
            edge[es].w = p[i][j];
        }
    }
    sort(edge + 1, edge + es + 1, cmp);
    bcj.init();
    int tot = 0;
    for (int i = 1; i <= es; i++) {
        int from = edge[i].from, to = edge[i].to, w = edge[i].w;
        if (bcj.find(from) != bcj.find(to)) {
            bcj.merge(from, to);
            tot += w;
        }
    }
    cout << tot << endl;

    return 0;
}
