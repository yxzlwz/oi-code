#include <bits/stdc++.h>
using namespace std;

char a[1001], t[1001], p[1001], e[1001];

int main()
{
    int qq;
    cin >> qq;
    cin >> a;
    while (qq--)
    {
        int q, m, n, ll;
        cin >> q;
        switch (q)
        {
        case 1:
            cin >> p;
            ll = strlen(a);
            for (int i = 0; i < strlen(p); i++)
            {
                a[ll + i] = p[i];
            }
            a[ll + strlen(p)] = '\0';
            cout << a << endl;
            break;
        case 2:
            cin >> m >> n;
            for (int i = m; i < m + n; i++)
            {
                t[strlen(t)] = a[i];
            }
            for (int i = 0; i < strlen(t); i++)
                a[i] = t[i];
            a[strlen(t)] = '\0';
            for (int i = 0; i < 1001; i++)
                t[i] = e[i];
            cout << a << endl;
            break;
        case 3:
            ll = strlen(a);
            cin >> m >> p;
            for (int i = ll - 1; i >= m; i--)
            {
                swap(a[i], a[i + strlen(p)]);
            }
            for (int i = m; i < strlen(p) + m; i++)
            {
                a[i] = p[i - m];
            }
            a[strlen(p) + ll] = '\0';
            cout << a << endl;
            break;
        case 4:
            cin >> p;
            bool had = 0;
            for (int i = 0; i <= strlen(a) - strlen(p); i++)
            {
                bool is = 1;
                for (int j = 0; j < strlen(p); j++)
                {
                    if (a[i + j] != p[j])
                    {
                        is = 0;
                        break;
                    }
                }
                if (is)
                {
                    cout << i << endl;
                    had = 1;
                    break;
                }
            }
            if (!had)
                cout << -1 << endl;
            break;
        }
    }
    return 0;
}