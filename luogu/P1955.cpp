#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1000005, MOD = 700001;

class LSH {
   private:
    int a[N];
    set<int> s;
    bool have(int x) { return s.count(x); }

   public:
    void init() {
        memset(a, 0, sizeof(a));
        s.clear();
    }
    int find(int x) {
        if (!have(x)) {
            int i = x % MOD;
            while (a[i]) i++;
            a[i] = x;
            s.insert(x);
            return i;
        }
        int i = x % MOD;
        while (a[i] != x) i++;
        return i;
    }
} lsh;

class BCJ {
   private:
    int f[N];

   public:
    void init() {
        for (int i = 0; i < N; i++) f[i] = i;
    }
    int find(int x) {
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    void merge(int x, int y) { f[find(x)] = find(y); }
} bcj;

stack<pii> st;

int main() {
    int t;
    cin >> t;
    while (t--) {
        bcj.init();
        lsh.init();
        while (!st.empty()) st.pop();
        int n;
        cin >> n;
        while (n--) {
            int a, b, c;
            cin >> a >> b >> c;
            a = lsh.find(a);
            b = lsh.find(b);
            if (c == 0)
                st.push(make_pair(a, b));
            else
                bcj.merge(a, b);
        }
        bool ok = true;
        while (!st.empty()) {
            pii temp = st.top();
            st.pop();
            if (bcj.find(temp.first) == bcj.find(temp.second)) {
                ok = false;
                break;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}