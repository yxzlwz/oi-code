#include <bits/stdc++.h>
using namespace std;

bool num1[32], num[32];

int main()
{
    long long n, ans = 0;
    cin >> n;
    int i = 0;
    while (n)
    {
        num1[i++] = n % 2;
        n /= 2;
    }
    for (int i = 0, j = 16; i < 16; i++, j++)
    {
        num[j] = num1[i];
        num[i] = num1[j];
    }
    for (int i = 0; i < 32; i++)
    {
        ans += num[i] * pow(2, i);
    }

    cout << ans;
    return 0;
}