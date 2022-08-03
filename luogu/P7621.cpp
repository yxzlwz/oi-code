#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double a, s = 0.0;
    int b;
    while (n--)
    {
        cin >> a >> b;
        s += a * double(b);
    }
    cout << fixed << setprecision(1) << float(int(s * 0.85 *10)) / 10.0;

    return 0;
}