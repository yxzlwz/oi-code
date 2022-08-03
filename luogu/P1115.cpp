#include <iostream>
using namespace std;

struct node
{
    long long value = 0, sum = 0;
} a[1000001];

int main()
{
    int n, max = -999999;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].value;
        a[i].sum = a[i - 1].sum + a[i].value;
        if (a[i].sum < a[i].value)
            a[i].sum = a[i].value;
        if (a[i].sum > max)
            max = a[i].sum;
    }
    cout << max;

    return 0;
}