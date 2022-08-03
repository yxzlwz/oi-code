#include <iostream>
using namespace std;

int n, m, t, sx, sy, fx, fy, a[11][11], lo[11][11], ans;
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int p, int q)
{
    if (p == fx && q == fy)
    {
        ans++;
        return;
    }
    int x, y;
    lo[p][q] = 1;
    for (int i = 0; i < 4; i++)
    {
        x = p + mv[i][0];
        y = q + mv[i][1];
        if (a[x][y] && !lo[x][y])
        {
            dfs(x, y);
        }
    }
    lo[p][q] = 0;
}

int main()
{
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = 1;
        }
    }
    int a1, a2;
    while (t--)
    {
        cin >> a1 >> a2;
        a[a1][a2] = 0;
    }
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}