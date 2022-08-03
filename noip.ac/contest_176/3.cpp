#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1000001;

int n, m, k;

pii edge[N << 1];
int ecnt;

class BCJ {
   private:
    int f[N];

   public:
    void init() {
        for (int i = 0; i < N; ++i) f[i] = i;
    }
    int find(int x) {
        if (f[x] != x) f[x] = find(f[x]);
        return f[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) f[x] = y;
    }
} bcj;

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edge[++ecnt] = pii(u, v);
    }
    for (int i = 1; i <= n; i++) {
        bcj.init();
        int cnt = 1;
        for (int j = 1; j <= ecnt; j++) {
            int u = edge[j].first, v = edge[j].second;
            if (u == i || v == i) continue;
            if (bcj.find(u) != bcj.find(v)) {
                bcj.merge(u, v);
                cnt++;
            }
        }
        if (cnt + k >= n)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
