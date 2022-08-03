#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    int step;
};

int a[100000001];
queue<node> que;

int main()
{
    int l, s, t, m, temp, MIN = 99999999;
    cin >> l >> s >> t >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        a[temp] = 1;
    }
    node q, tmp;
    q.x = 0;
    q.step = 0;
    que.push(q);
    while (!que.empty())
    {
        q = que.front();
        que.pop();
        for (int i = s; i <= t; i++)
        {
            if (q.x + i >= l)
            {
                MIN = min(MIN, q.step);
                continue;
            }
            tmp.x = q.x + i;
            tmp.step = a[tmp.x] ? q.step + 1 : q.step;
            que.push(tmp);
        }
    }
    cout << MIN;

    return 0;
}