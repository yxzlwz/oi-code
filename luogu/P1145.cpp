#include <bits/stdc++.h>
using namespace std;

struct node
{
    int id;
    bool good;
    int next;
} a[101];

int main()
{
    int k, m = 0;
    cin >> k;


    while (++m)
    {
        for (int i = 0; i < k; i++)
        {
            a[i].id = i + 1;
            a[i].good = 1;
            a[i].next = i + 1;
        }
        for (int i = k; i < k * 2; i++)
        {
            a[i].id = i + 1;
            a[i].good = 0;
            a[i].next = i + 1;
        }
        a[k * 2 - 1].next = 0;
        int died = 0, cur = k * 2 - 1;
        bool flag = true;
        while (died < k)
        {
            for (int i = 1; i < m; i++)
            {
                cur = a[cur].next;
            }
            if (a[a[cur].next].good)
            {
                flag = false;
                break;
            }
            else
            {
                died++;
                a[cur].next = a[a[cur].next].next;
            }
        }
        if (flag)
        {
            cout << m;
            return 0;
        }
    }
}