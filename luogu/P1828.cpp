#include <bits/stdc++.h>
using namespace std;

int a[801][801], b[501], dis[801], num[801], w[801][801], team[1605];
bool exist[801];

int main() {
    int n, p, c;
    cin >> n >> p >> c;
    for (int i = 1; i <= p; i++) {
        b[i] = 0;
        num[i] = 0;
        for (int j = 1; j <= p; j++) w[i][j] = 0x7f7f7f7f;
    }
    for (int i = 1; i <= n; i++) cin >> b[i];

    int x, y, t;
    for (int i = 1; i <= c; i++) {
        cin >> x >> y >> t;
        w[x][y] = w[y][x] = t;
        a[x][++num[x]] = y;
        a[y][++num[y]] = x;
    }
    int min1 = 0x7f7f7f7f;
    int head, tail, tot, u;
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= p; j++) dis[j] = 0x7f7f7f7f;
        memset(team, 0, sizeof(team));
        memset(exist, false, sizeof(exist));
        dis[i] = 0;
        team[1] = i;
        head = 0;
        tail = 1;
        exist[i] = true;
        do {
            head++;
            head = (head - 1) % 1601 + 1;
            u = team[head];
            exist[u] = false;
            for (int j = 1; j <= num[u]; j++) {
                if (dis[a[u][j]] > dis[u] + w[u][a[u][j]]) {
                    dis[a[u][j]] = dis[u] + w[u][a[u][j]];
                    if (!exist[a[u][j]]) {
                        tail++;
                        tail = (tail - 1) % 1601 + 1;
                        team[tail] = a[u][j];
                        exist[a[u][j]] = true;
                    }
                }
            }
        } while (head != tail);
        tot = 0;
        for (int j = 1; j <= n; j++) tot += dis[b[j]];
        if (tot < min1) min1 = tot;
    }
    cout << min1;
    return 0;
}