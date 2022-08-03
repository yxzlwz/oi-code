#include <bits/stdc++.h>
using namespace std;
bool zs[10001] = {0, 0, 1};
int main()
{
    for (int i = 3; i <= 10000; i += 2)
    {
        bool is = 1;
        for (int j = 1; j <= i / 2; j++)
        {
            if (zs[j] && i % j == 0)
            {
                is = 0;
                break;
            }
        }
        if (is)
            zs[i] = is;
    }

    int n;
    cin >> n;
    for (int i = 4; i <= n; i += 2)
    {
        for (int j = 2; j <= i / 2; j++)
        {
            if (zs[j] && zs[i - j])
            {
                printf("%d=%d+%d\n", i, j, i - j);
                break;
            }
        }
    }
    return 0;
}