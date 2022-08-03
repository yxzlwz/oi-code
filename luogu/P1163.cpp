#include <bits/stdc++.h>
using namespace std;

long long check(double a, double b, double l, long long cc)
{
    long long c = 0;
    while (a > 0 && ++c < cc + 10)
    {
        a += a * l;
        a -= b;
    }
    cout << a << endl;
    return c;
}

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    double l = 0.0001, r = 100;
    while (l + 0.0001 < r)
    {
        double mid = (l + r) / 2;
        if (check(a, b, mid, c) > c)
            r = mid;
        else
            l = mid;
    }
    // cout << l;
    printf("%.1lf", l * 100.0);

    return 0;
}