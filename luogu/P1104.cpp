#include <bits/stdc++.h>
using namespace std;

struct node
{
    string name;
    int y, m, d;
    int num;
} a[100001];

bool cmp(node p, node q)
{
    if (p.y != q.y)
        return p.y < q.y;
    else if (p.m != q.m)
        return p.m < q.m;
    else if (p.d != q.d)
        return p.d < q.d;
    else
        return p.num > q.num;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].name >> a[i].y >> a[i].m >> a[i].d;
        a[i].num = i;
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
        cout << a[i].name << endl;

    return 0;
}