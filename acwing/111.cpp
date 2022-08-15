#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int n, cnt;
piii cow[50001];
priority_queue<pii> q;

int ans[50001];

bool cmp(const piii &a, const piii &b) { return a.first.first < b.first.first; }

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cow[i].first.first >> cow[i].first.second;
        cow[i].second = i;
    }
    sort(cow + 1, cow + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if (q.empty() || -q.top().first >= cow[i].first.first) {
            q.push(make_pair(-cow[i].first.second, ++cnt));
            ans[cow[i].second] = cnt;
        } else {
            pii t = q.top();
            q.pop();
            t.first = -cow[i].first.second;
            ans[cow[i].second] = t.second;
            q.push(t);
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}