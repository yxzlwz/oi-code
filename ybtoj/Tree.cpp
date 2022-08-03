#include <bits/stdc++.h>
using namespace std;

const int V = 50001, E = 100001;
int v, e, tot;

struct EDGE {
    int from, to, w, col;
} edge[E];

bool cmp(EDGE x, EDGE y) {
    if (x.w != y.w) {
        return x.w < y.w;
    }
    return x.col < y.col;
}

class BCJ {
   private:
    int f[V];

   public:
    void init() {
        for (int i = 1; i < V; i++) f[i] = i;
    }
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        f[y] = x;
    }
} bcj;

int kruscal(int mid) {
    int cnt = 0;
    tot = 0;
    bcj.init();
    for (int i = 1; i <= e; i++) {
        if (edge[i].col == 0) edge[i].w += mid;
    }
    sort(edge + 1, edge + e + 1, cmp);
    for (int i = 1; i <= e; i++) {
        int from = edge[i].from, to = edge[i].to, w = edge[i].w;
        if (bcj.find(from) != bcj.find(to)) {
            bcj.merge(from, to);
            if (edge[i].col == 0) {
                cnt++;
                tot += (w - mid);
            } else {
                tot += w;
            }
        }
    }
    for (int i = 1; i <= e; i++) {
        if (edge[i].col == 0) edge[i].w -= mid;
    }
    return cnt;
}

int main() {
    int need;
    cin >> v >> e >> need;
    for (int i = 1; i <= e; i++) {
        cin >> edge[i].from >> edge[i].to >> edge[i].w >> edge[i].col;
    }
    int l = -101, r = 101, mid;
    while (l + 1 <= r) {
        mid = (l + r) / 2;
        int temp = kruscal(mid);
        if (temp > need) {
            l = mid + 1;
        } else if (temp < need) {
            r = mid - 1;
        } else {
            cout << tot << endl;
            return 0;
        }
    }
}
