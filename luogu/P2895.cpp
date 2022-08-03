#include <iostream>
#include <cstring>
using namespace std;

int m, map[401][401];
int mv[5][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 0}};
bool visited[401][401];

struct node
{
    int x, y, step;
} que[100000009];

int main()
{
    memset(map, -1, sizeof(map));
    cin >> m;
    int xx, yy, xxx, yyy, tt;
    while (m--)
    {
        cin >> xx >> yy >> tt;
        for (int i = 0; i < 5; i++)
        {
            xxx = xx + mv[i][0];
            yyy = yy + mv[i][1];
            if (xxx >= 0 && yyy >= 0)
            {
                if (map[xxx][yyy] == -1)
                {
                    map[xxx][yyy] = tt;
                }
                else
                {
                    map[xxx][yyy] = tt < map[xxx][yyy] ? tt : map[xxx][yyy];
                }
            }
        }
    }

    int head = 0, tail = 1;
    que[head].x = 0;
    que[head].y = 0;
    que[head].step = 0;
    visited[0][0] = 1;
    int x, y;
    while (head < tail)
    {
        for (int i = 0; i < 4; i++)
        {
            x = que[head].x + mv[i][0];
            y = que[head].y + mv[i][1];
            if (x >= 0 && y >= 0 && !visited[x][y] && (map[x][y] == -1 || que[head].step + 1 < map[x][y]))
            {
                if (map[x][y] == -1)
                {
                    cout << que[head].step + 1 << endl;
                    return 0;
                }
                que[tail].x = x;
                que[tail].y = y;
                que[tail].step = que[head].step + 1;
                visited[x][y] = 1;
                tail++;
            }
        }
        head++;
    }

    cout << -1;
    return 0;
}