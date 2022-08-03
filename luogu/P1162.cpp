#include <bits/stdc++.h>
using namespace std;

int n, m, t, sx, sy, fx, fy, a[101][101], lo[101][101], ans;
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct node
{
    int x, y, step;
} que[1000001];

void doit(int p, int q)
{
    // cout << "!" << p << " " << q << endl;
    int head = 0, tail = 1;
    que[head].x = p;
    que[head].y = q;
    a[p][q] = 2;
    while (head < tail)
    {
        int x, y;
        for (int i = 0; i < 4; i++)
        {

            x = que[head].x + mv[i][0];
            y = que[head].y + mv[i][1];
            // cout << x << " " << y << " " << a[x][y] << endl;

            if (a[x][y] == 0)
            {
                // cout<<x<<" "<<y<<endl;
                que[tail].x = x;
                que[tail].y = y;
                a[x][y] = 2;
                tail++;
            }
        }
        head++;
    }
}

bool bfs(int p, int q)
{
    memset(lo, 0, sizeof(lo));
    int head = 0, tail = 1;
    que[head].x = p;
    que[head].y = q;
    lo[p][q] = 1;
    while (head < tail)
    {
        int x, y;
        for (int i = 0; i < 4; i++)
        {
            x = que[head].x + mv[i][0];
            y = que[head].y + mv[i][1];
            if (!a[x][y] && !lo[x][y])
            {
                if (!(x > 0 && y > 0 && x <= n && y <= n))
                {

                    return false;
                }
                que[tail].x = x;
                que[tail].y = y;
                lo[x][y] = 1;
                tail++;
            }
        }
        head++;
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (!a[i][j] && bfs(i, j))
            {
                doit(i, j);
                break;
            }
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}