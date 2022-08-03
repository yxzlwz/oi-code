#include <bits/stdc++.h>
using namespace std;

const int N = 360, M = 16;
int n, m, c1, c2, dist;
int sx, sy, tx, ty;
int cov[N][N];
bool person[N][N];

struct data {
    int x, y, u1, u2;
    data(int v1, int v2, int v3, int v4) : x(v1), y(v2), u1(v3), u2(v4) {}
};

int d[N][N][M][M];
bool vis[N][N][M][M];
const int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1},
          dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

inline bool exist(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

void bfs() {
    queue<data> q;
    d[sx][sy][0][0] = 0;
    vis[sx][sy][0][0] = true;
    q.push(data(sx, sy, 0, 0));
    while (!q.empty()) {
        data u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if (exist(nx, ny) && !person[nx][ny]) {
                if (cov[nx][ny]) {
                    if (u.u1 + 1 <= c1 && !vis[nx][ny][u.u1 + 1][u.u2]) {
                        d[nx][ny][u.u1 + 1][u.u2] = d[u.x][u.y][u.u1][u.u2] + 1;
                        vis[nx][ny][u.u1 + 1][u.u2] = true;
                        q.push(data(nx, ny, u.u1 + 1, u.u2));
                    }
                } else {
                    if (!vis[nx][ny][u.u1][u.u2]) {
                        d[nx][ny][u.u1][u.u2] = d[u.x][u.y][u.u1][u.u2] + 1;
                        vis[nx][ny][u.u1][u.u2] = true;
                        q.push(data(nx, ny, u.u1, u.u2));
                    }
                }
            }
        }
        if (u.u2 + 1 <= c2) {
            for (int i = 0; i < 4; i++) {
                int nx = u.x + dx[i] * dist, ny = u.y + dy[i] * dist;
                if (exist(nx, ny) && !person[nx][ny]) {
                    if (cov[nx][ny]) {
                        if (u.u1 + 1 <= c1 &&
                            !vis[nx][ny][u.u1 + 1][u.u2 + 1]) {
                            d[nx][ny][u.u1 + 1][u.u2 + 1] =
                                d[u.x][u.y][u.u1][u.u2] + 1;
                            vis[nx][ny][u.u1 + 1][u.u2 + 1] = true;
                            q.push(data(nx, ny, u.u1 + 1, u.u2 + 1));
                        }
                    } else {
                        if (!vis[nx][ny][u.u1][u.u2 + 1]) {
                            d[nx][ny][u.u1][u.u2 + 1] =
                                d[u.x][u.y][u.u1][u.u2] + 1;
                            vis[nx][ny][u.u1][u.u2 + 1] = true;
                            q.push(data(nx, ny, u.u1, u.u2 + 1));
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> c1 >> c2 >> dist;
    char s[4];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%s", s);
            if (s[0] == 'S') {
                sx = i;
                sy = j;
            } else if (s[0] == 'T') {
                tx = i;
                ty = j;
            } else if (s[0] != '.') {
                person[i][j] = true;
                int len = strlen(s), num = 0;
                for (int k = 0; k < len; k++) num = num * 10 + s[k] - '0';
                for (int t = max(1, i - num + 1); t <= min(n, i + num - 1);
                     t++) {
                    int l = max(1, j - num + 1 + abs(t - i)),
                        r = min(m, j + num - 1 - abs(t - i));
                    cov[t][l]++;
                    cov[t][r + 1]--;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cov[i][j] += cov[i][j - 1];
    bfs();
    int t = n * m, u1, u2;
    for (int i = 0; i <= c1 + c2; i++) {
        for (int j = 0; j <= i; j++) {
            if (d[tx][ty][i][j] < t && vis[tx][ty][j][i]) {
                t = d[tx][ty][j][i];
                u1 = j;
                u2 = i - j;
            }
        }
    }
    if (t == n * m)
        cout << -1 << endl;
    else
        cout << t << " " << u1 << " " << u2 << endl;
    return 0;
}
