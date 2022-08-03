#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<double, int> pdi;

const int N = 5001;
pii city[N];
double d[N];
bool vis[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        city[i] = make_pair(a, b);
    }

    double ans = 0;

    for (int i = 1; i <= n; i++) d[i] = 1e8;
    d[1] = 0;
    // priority_queue<pdi> pq;
    // pq.push(make_pair(0, 1));

    int cnt = 1;

    // while (cnt < n) {
    //     pdi p = pq.top();
    //     pq.pop();
    //     int u = p.second;
    //     cout << cnt << " " << u << endl;
    //     if (vis[u]) continue;
    //     vis[u] = true;
    //     cout << cnt << endl;
    //     for (int i = 1; i <= n; i++) {
    //         if (vis[i]) continue;
    //         double w = sqrt(pow(city[u].first - city[i].first, 2) +
    //                         pow(city[u].second - city[i].second, 2));
    //         if (w < d[i]) {
    //             d[i] = w;
    //             pq.push(make_pair(d[i], i));
    //         }
    //     }
    //     cnt++;
    // }

    for (int i = 1; i <= n; i++) {
        double minn = 1e8;
        int index = -1;
        for (int j = 1; j <= n; j++) {
            if (vis[j]) continue;
            if (d[j] < minn) {
                minn = d[j];
                index = j;
            }
        }
        ans += minn;
        vis[index] = true;
        for (int j = 1; j <= n; j++) {
            double s = sqrt(pow(city[index].first - city[j].first, 2) +
                            pow(city[index].second - city[j].second, 2));
            if (s < d[j]) d[j] = s;
        }
    }
    cout << fixed << setprecision(2) << ans;
}