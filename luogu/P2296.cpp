#include <bits/stdc++.h>
using namespace std;

const int N = 10001;

vector<int> e1[N], e2[N];

int n, m, s, t;
bool touch[N], available[N], vis[N];

int main() {
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        e1[a].push_back(b);
        e2[b].push_back(a);
    }
    cin >> s >> t;

    queue<int> q1;
    q1.push(t);
    touch[t] = true;
    while (!q1.empty()) {
        int x = q1.front();
        q1.pop();
        for (int i = 0; i < e2[x].size(); i++) {
            int y = e2[x][i];
            if (!touch[y]) {
                touch[y] = true;
                q1.push(y);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 0; j < e1[i].size(); j++) {
            int y = e1[i][j];
            if (!touch[y]) {
                flag = false;
                break;
            }
        }
        if (flag) available[i] = true;
    }

    queue<pair<int, int> > q2;
    q2.push(make_pair(s, 0));
    vis[s] = true;
    while (!q2.empty()) {
        int x = q2.front().first, d = q2.front().second;
        q2.pop();
        for (int i = 0; i < e1[x].size(); i++) {
            int y = e1[x][i];
            if (!vis[y] && available[y]) {
                if (y == t) {
                    cout << d + 1 << endl;
                    return 0;
                }
                vis[y] = true;
                q2.push(make_pair(y, d + 1));
            }
        }
    }

    cout << -1 << endl;

    return 0;
}