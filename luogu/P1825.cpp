#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ex, ey;
char mp[301][301];
int send[301][301][3], hadLetter[100][3];
short mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct node
{
    int x, y, step;
};
queue<node> que;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            switch (mp[i][j])
            {
            case '@':
                sx = i;
                sy = j;
                break;
            case '=':
                ex = i;
                ey = j;
                break;
            }
            if (mp[i][j] >= 'A' && mp[i][j] <= 'Z')
            {
                if (hadLetter[mp[i][j]][0] == 1) // 如果这个字母出现过了
                {
                    send[i][j][0] = 1; // 点(i,j)存在传送关系
                    send[i][j][1] = hadLetter[mp[i][j]][1]; // 传送的目标点的x坐标
                    send[i][j][2] = hadLetter[mp[i][j]][2]; // 传送的目标点的y坐标
                    send[hadLetter[mp[i][j]][1]][hadLetter[mp[i][j]][2]][0] = 1; // 该字母上一次出现时的点也存在传送关系
                    send[hadLetter[mp[i][j]][1]][hadLetter[mp[i][j]][2]][1] = i; // 传送的目标点的x坐标
                    send[hadLetter[mp[i][j]][1]][hadLetter[mp[i][j]][2]][2] = j; // 传送的目标点的y坐标
                }
                else
                {
                    hadLetter[mp[i][j]][0] = 1; // 这个字母出现过了
                    hadLetter[mp[i][j]][1] = i; // 该字母第一次出现时（也就是这次）的x坐标
                    hadLetter[mp[i][j]][2] = j; // y坐标
                }
            }
        }
    }

    node t;
    t.x = sx;
    t.y = sy;
    t.step = 0;
    que.push(t);
    mp[sx][sy] = '#';
    int x, y;
    while (!que.empty())
    {
        node q = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            x = q.x + mv[i][0];
            y = q.y + mv[i][1];
            if (x >= 0 && y >= 0 && x < n && y < m && mp[x][y] != '#')
            {
                /*
                到点(x,y)有两种方式，走过去or传送过去
                所以普通点接受走一次，而有传送关系的接受两种方式各走一次
                所以每个点只需要标注是否以“走过去”这个方法到达过
                这样对于关联传送关系的点也就等于标记了另一个端点被通过传送方式到过了
                如果你脑子够用，补充说明见程序最后
                */
                mp[x][y] = '#';
                if (x == ex && y == ey)
                {
                    cout << q.step + 1;
                    return 0;
                }
                if (send[x][y][0])
                {
                    int xx = x, yy = y;
                    x = send[xx][yy][1];
                    y = send[xx][yy][2];
                    // mp[x][y] = '#';
                }
                t.x = x;
                t.y = y;
                t.step = q.step + 1;
                que.push(t);
            }
        }
    }

    return 0;
}
/*
补充说明：
设a,b两点存在传送关系
∵传送为强制
∴走到a的最小步数实则为到达b的最小步数，反之亦然
∴锁住a这个点的实际意义是我们到过了b，因为锁住后就不可能再到达b了
同时对于直接被传送到b的情况而言，这一次踩到a是无意义的，无法从a继续向周围走
而有意义的抵达a应是先踩到b然后被传送过来
所以b这个点暂时仍不能标记（如果标记了就不可能有意义地到达a了）
而a仍然要标记，否则会出现在更多步数的时候再次访问b
*/
