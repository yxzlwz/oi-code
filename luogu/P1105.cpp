#include <cstdio>
#include <iostream>
using namespace std;

struct node
{
    int h = 0, l, r, num;
} a[10001];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].h >> a[i].l >> a[i].r;
        a[i].num = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int lmax = 0, rmax = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j].h < a[i].h && a[j].r > a[i].l && a[j].l < a[i].l && a[j].h > a[lmax].h)
                lmax = j;
            if (a[j].h < a[i].h && a[j].r > a[i].r && a[j].l < a[i].r && a[j].h > a[rmax].h)
                rmax = j;
        }
        printf("%d %d\n", lmax, rmax);
    }

    return 0;
}