#include <iostream>
#include <cstring>
#include<queue>
using namespace std;

int m, map[401][401];
int mv[5][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 0}};
bool visited[401][401];

struct node
{
    int x, y, step;
};

queue <node> que;

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
    node q, t;
    t.x = 0;
    t.y = 0;
    t.step = 0;
    que.push(t);
    visited[0][0] = 1;
    int x, y;
    while (!que.empty())
    {
        q = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            x = q.x + mv[i][0];
            y = q.y + mv[i][1];
            if (x >= 0 && y >= 0 && !visited[x][y] && (map[x][y] == -1 || q.step + 1 < map[x][y]))
            {
                if (map[x][y] == -1)
                {
                    cout << q.step + 1 << endl;
                    return 0;
                }
                t.x = x;
                t.y = y;
                t.step = q.step + 1;
                que.push(t);
                visited[x][y] = 1;
            }
        }
    }

    cout << -1;
    return 0;
}