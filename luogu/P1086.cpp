#include <bits/stdc++.h>
using namespace std;

struct MP {
    int x, y, w;
} mp[501];

bool cmp(MP a, MP b) { return a.w > b.w; }

int dis(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2) + 1;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++, cnt++) {
            mp[cnt].x = i;
            mp[cnt].y = j;
            cin >> mp[cnt].w;
        }
    }
    sort(mp + 1, mp + 1 + cnt, cmp);

    int i = 1;
    int d = mp[i].x + 1, w = mp[i].w;
    if (d * 2 > k) {
        cout << 0;
        return 0;
    }
    while (true) {
        i++;
        d += dis(mp[i].x, mp[i].y, mp[i - 1].x, mp[i - 1].y);
        if (d + mp[i].x > k) break;
        w += mp[i].w;
    }
    cout << w;

    return 0;
}