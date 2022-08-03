#include <iostream>
using namespace std;
int w[10001];
int main()
{
    int n, c, maxx = 0;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
    {
        int s = 0, cnt = 0;
        for (int j = i; j < n; j++)
        {
            if (s + w[j] <= c)
            {
                s += w[j];
                cnt++;
            }
            if (s == c)
                break;
        }
        maxx = maxx < cnt ? cnt : maxx;
    }

    cout << maxx;
}