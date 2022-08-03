#include <bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
        a[i] = i + 1;
    a[n] = 1;
    int j = n, k = 1, p = 0;
    while (p < n)
    {
        while (k < m)
        {
            j = a[j];
            k++;
        }
        cout << a[j] << " ";
        a[j] = a[a[j]];
        k = 1;
        p++;
    }
}