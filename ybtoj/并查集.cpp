#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

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
        int a = find(x), b = find(y);
        if (a != b) f[a] = b;
    }
} bcj;

int main() {
    int n, m;
    cin >> n >> m;
    bcj.init();
    while (m--) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) {
            bcj.merge(x, y);
        } else {
            if (bcj.find(x) == bcj.find(y))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
}
