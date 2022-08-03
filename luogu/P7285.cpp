#include <iostream>
using namespace std;
int k, n, l, r, s[10000001];
int main()
{
    cin >> k;
    while (k--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 1)
            {
                l = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 1)
            {
                r = i;
                break;
            }
        }
        int max1 = 0, cnt0 = 0;
        for (int i = l; i < r; i++)
        {
            if (s[i] == 0)
            {
                cnt0++;
                s[i] = 1;
            }
            else
            {
                int cntt = 0;
                int j = i;
                while (s[j++] == 1)
                    cntt++;
                if (cntt > max1)
                    max1 = cntt;
            }
        }
        cout << r - l + 1 - cnt0 << endl;
        for (int i = 0; i < n - 1; i++)
            cout << s[i] << " ";
        cout << s[n - 1] << endl;
    }
}