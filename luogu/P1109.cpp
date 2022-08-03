#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, l, r, a[100], summ = 0, x = 0, y = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        summ += a[i];
    }
    cin >> l >> r;
    if (summ > n * r || summ < n * l)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] < l)
            x += l - a[i];
        else if (a[i] > r)
            y += a[i] - r;
    }
    cout << max(x, y);

    return 0;
}