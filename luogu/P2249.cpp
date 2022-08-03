#include <bits/stdc++.h>
using namespace std;

int a[10000000];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (m--)
    {
        int t;
        cin >> t;
        int l = 0, r = n - 1, mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (t == a[mid])
                break;
            if (a[mid] < t)
                l = mid + 1;
            else
                r = mid - 1;
        }
        while (a[mid - 1] == a[mid])
            mid--;
        if (a[mid] == t)
            cout << mid + 1;
        else
            cout << -1;
        if (m)
            cout << " ";
    }

    cout << endl;

    return 0;
}