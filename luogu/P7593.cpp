#include <iostream>
using namespace std;
int main()
{
    int t;
    long long n, k, s, l, r;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;
        l = (1 + k) * k / 2;
        r = (n - k + 1 + n) * k / 2;
        if (s >= l && s <= r)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}