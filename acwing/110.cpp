#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int c, l;
pii nn[5001], fss[5001];

bool cmp1(const pii &a, const pii &b) { return a.second < b.second; }

int main() {
    cin >> c >> l;
    for (int i = 1; i <= c; ++i) cin >> nn[i].first >> nn[i].second;
    sort(nn + 1, nn + c + 1, cmp1);
    for (int i = 1; i <= l; ++i) cin >> fss[i].first >> fss[i].second;
    sort(fss + 1, fss + l + 1);
    int cnt = 0;
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= l; j++) {
            if (!fss[j].second) continue;
            if (nn[i].first <= fss[j].first && fss[j].first <= nn[i].second) {
                fss[j].second--;
                ++cnt;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}