#include <bits/stdc++.h>
using namespace std;

const int N = 30005;

class BCJ {
   private:
    short f[N];
    vector<short> g[N];

   public:
    void init() {
        for (int i = 0; i < N; i++) {
            f[i] = i;
            g[i].push_back(i);
        }
    }
    int find(int x) {
        if (f[x] != x) f[x] = find(f[x]);
        return f[x];
    }
    void merge(int x, int y) {
        int a = find(x), b = find(y);
        if (a != b) {
            f[a] = b;
            for (int i = 0; i < g[a].size(); i++) {
                g[b].push_back(g[a][i]);
            }
            g[a].clear();
        }
    }
    int manage(int x, int y) {
        int z = find(x);
        int a, b;
        a = b = 0;
        for (int i = 0; i < g[z].size(); i++) {
            if (g[z][i] == x) {
                a = i;
            } else if (g[z][i] == y) {
                b = i;
            }
        }
        return abs(b - a) - 1;
    }
} bcj;

int main() {
    int m;
    cin >> m;
    bcj.init();
    while (m--) {
        char z;
        int x, y;
        cin >> z >> x >> y;
        if (z == 'M')
            bcj.merge(x, y);
        else {
            if (bcj.find(x) == bcj.find(y))
                cout << bcj.manage(x, y) << endl;
            else
                cout << "-1" << endl;
        }
    }
}
