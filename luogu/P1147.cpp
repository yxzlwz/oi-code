#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (((i + j) * (j - i + 1) / 2) == n)
            {
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}