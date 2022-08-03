#include <bits/stdc++.h>
using namespace std;

struct node
{
    int num, s, w;
} a[1000001];

queue<node> x;
queue<node> y;

void px()
{
    int i = 0;
    while (!x.empty() && !y.empty())
    {
        if (x.front().s > y.front().s)
        {
            a[i++] = x.front();
            x.pop();
        }
        else if (x.front().s < y.front().s)
        {
            a[i++] = y.front();
            y.pop();
        }
        else if (x.front().num < y.front().num)
        {
            a[i++] = x.front();
            x.pop();
        }
        else
        {
            a[i++] = y.front();
            y.pop();
        }
    }
    while (!x.empty())
    {
        a[i++] = x.front();
        x.pop();
    }
    while (!y.empty())
    {
        a[i++] = y.front();
        y.pop();
    }
}

// bool cmp(struct node m, struct node p)
bool cmp(node m, node p)
{
    if (m.s != p.s)
        return m.s > p.s;
    else
        return m.num > p.num;
}

int main()
{
    int n, r, q;
    cin >> n >> r >> q;
    n *= 2;
    for (int i = 0; i < n; i++)
        a[i].num = i + 1;
    for (int i = 0; i < n; i++)
        cin >> a[i].s;
    for (int i = 0; i < n; i++)
        cin >> a[i].w;
    sort(a, a + n, cmp);

    while (r--)
    {
        for (int i = 0; i < n; i += 2)
        {
            if (a[i].w > a[i + 1].w)
            {
                a[i].s++;
                x.push(a[i]);
                y.push(a[i + 1]);
            }
            else
            {
                a[i + 1].s++;
                x.push(a[i + 1]);
                y.push(a[i]);
            }
        }
        px();
    }

    cout << a[q - 1].num;

    return 0;
}