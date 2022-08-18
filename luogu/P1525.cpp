#include <bits/stdc++.h>
using namespace std;

const int N = 20001, M = 100001;

struct CT {
    int a, b, c;
} ct[M];

bool cmp(const CT &x, const CT &y) { return x.c > y.c; }

class BCJ {
   private:
    int f[N];

   public:
    void init() {
        for (int i = 0; i < N; i++) f[i] = i;
    }
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    inline void merge(int x, int y) { f[find(x)] = find(y); }
};

int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> ct[i].a >> ct[i].b >> ct[i].c;
    }
    sort(ct + 1, ct + 1 + m, cmp);
    int x = ct[1].a, y = ct[1].b;
    BCJ b;
    b.init();
    for (int i = 2; i <= m; i++) {
        if (b.find(ct[i].a) == b.find(ct[i].b)) {
            cout << ct[i].c << endl;
            return 0;
        }
            
    }
}