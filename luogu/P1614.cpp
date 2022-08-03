#include <iostream>
using namespace std;
int main()
{
    int a[10001], n, m, ans = 1000000;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = m; i <= n; i++)
    {
        int su = 0;
        for (int j = i - m; j < i; j++)
            su += a[j];
        if (su < ans)
            ans = su;
    }
    cout << ans;
}