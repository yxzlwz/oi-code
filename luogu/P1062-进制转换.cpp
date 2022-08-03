#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k, n;
    cin >> k >> n;
    bool ejz[1000001];
    int i = 0;
    while (n)
    {
        ejz[i++] = n % 2;
        n /= 2;
    }
    long long ans = 0;
    for (; i >= 0; i--)
    {
        ans += ejz[i] * pow(k, i);
    }

    cout << ans;

    return 0;
}