#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[100001], h[100001];
typedef pair<int, int> pii;
signed main() {
    cin >> n;
    while (n) {
        int maxx = 0;
        stack<pii> s;
        for (int i = 1; i <= n; i++) cin >> h[i];
        h[n + 1] = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (!s.empty() && h[i] > s.top().first) {
                s.push(make_pair(h[i], i));
            } else {
                while (!s.empty() && s.top().first > h[i]) {
                    int x = s.top().first, y = s.top().second;
                    s.pop();
                    maxx = max(maxx, abs(y) * x);
                }
                s.push(make_pair(h[i], i));
            }
        }
        // for (int i = 1; i <= n; i++) maxx = max(maxx, a[i]);
        cout << maxx << endl;
        cin >> n;
    }
    return 0;
}
