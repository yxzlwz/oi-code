#include <iostream>
using namespace std;
int a[100001];
int main()
{
    long long t, len = 0, summ = 0;
    while (cin >> t)
    {
        a[len++] = t;
    }

    for (int i = 1; i <= len; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            for (int k = j; k < j + i; k++)
            {
                summ += a[k];
            }
        }
    }

    cout<<summ;

    return 0;
}