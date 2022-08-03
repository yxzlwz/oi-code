#include <bits/stdc++.h>
using namespace std;

struct node
{
    int n, c, m, e, s;
} a[1000];

bool cmp(node x, node y)
{
    if (x.s != y.s)
        return x.s > y.s;
    else if (x.c != y.c)
        return x.c > y.c;
    else
        return x.n < y.n;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i].n = i;
        cin >> a[i].c >> a[i].m >> a[i].e;
        a[i].s = a[i].c + a[i].m + a[i].e;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= 5; i++)
        printf("%d %d\n", a[i].n, a[i].s);

    return 0;
}