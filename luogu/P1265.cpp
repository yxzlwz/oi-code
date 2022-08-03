#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<double, pii> piii;

const int N = 5001;
vector<piii> e;
vector<pii> city;

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

int main() {
    int n;
    cin >> n;
    bcj.init();
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        city.push_back(make_pair(a, b));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double d = sqrt(pow(city[i].first - city[j].first, 2) +
                            pow(city[i].second - city[j].second, 2));
            e.push_back(make_pair(d, make_pair(i, j)));
        }
    }
    sort(e.begin(), e.end());
    int cnt = 0;
    double ans = 0;
    for (int i = 0; i < e.size(); i++) {
        int a = e[i].second.first, b = e[i].second.second;
        double w = e[i].first;
        if (bcj.find(a) != bcj.find(b)) {
            bcj.merge(a, b);
            ans += w;
            cnt++;
        }
    }

    if (cnt == n - 1)
        cout << fixed << setprecision(2) << ans;
    else
        cout << "orz";
}