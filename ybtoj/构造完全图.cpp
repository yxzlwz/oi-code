#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n;
long long ans, cnt[N];

struct EDGE {
    int from, to;
    long long w;
} edge[N];

bool cmp(EDGE x, EDGE y) { return x.w < y.w; }

class BCJ {
   private:
    int f[N];

   public:
    void init() {
        for (int i = 1; i < N; i++) f[i] = i;
    }
    int find(int x) {
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        f[y] = x;
        cnt[x] += cnt[y];
    }
} bcj;

int main() {
    for (int i = 0; i < N; i++) cnt[i] = 1;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> edge[i].from >> edge[i].to >> edge[i].w;
        ans += edge[i].w;
    }
    sort(edge + 1, edge + n, cmp);
    bcj.init();
    for (int i = 1; i < n; i++) {
        int x = bcj.find(edge[i].from), y = bcj.find(edge[i].to);
        if (x != y) {
            ans += (cnt[x] * cnt[y] - 1) * (edge[i].w + 1);
            bcj.merge(edge[i].from, edge[i].to);
        }
    }
    cout << ans << endl;
    return 0;
}