#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int n;
typedef pair<int, int> pii;
pii a[N];

inline bool cmp(const pii &l, const pii &r) { return l.second < r.second; }

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1, cmp);
    int cnt = 1, end = a[1].second, i = 1;
    while (++i <= n) {
        if (a[i].first >= end) {
            cnt++;
            end = a[i].second;
        }
    }
    cout << cnt;
}