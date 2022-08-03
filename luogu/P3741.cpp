#include <bits/stdc++.h>
using namespace std;

int n;
string ss;
bool s[100001];

int cnt()
{
    int a = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 0 && s[i + 1] == 1)
            a++;
    }
    return a;
}

int main()
{
    cin >> n >> ss;
    int m = 0;
    for (int i = 0; i < n; i++)
        if (ss[i] == 'V')
            s[i] = 0;
        else
            s[i] = 1;
    m = max(m, cnt());
    for (int i = 0; i < n; i++)
    {
        s[i] = !s[i];
        m = max(m, cnt());
        s[i] = !s[i];
    }

    cout << m;

    return 0;
}