#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, ans[401][401];
int mv[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

struct node {
    int x, y, step;
} que[1000001];

int main() {
    cin >> n >> m >> x >> y;
    memset(ans, -1, sizeof(ans));
    int head = 0, tail = 1;
    que[head].x = x;
    que[head].y = y;
    que[head].step = 0;
    ans[x][y] = 0;
    while (head < tail) {
        int x, y;
        for (int i = 0; i < 8; i++) {
            x = que[head].x + mv[i][0];
            y = que[head].y + mv[i][1];
            if (x > 0 && y > 0 && x <= n && y <= m && ans[x][y] == -1) {
                que[tail].x = x;
                que[tail].y = y;
                que[tail].step = que[head].step + 1;
                ans[x][y] = que[tail].step;
                tail++;
            }
        }
        head++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            cout << left << setw(5) << ans[i][j];
        }
        cout << ans[i][m] << endl;
    }
}