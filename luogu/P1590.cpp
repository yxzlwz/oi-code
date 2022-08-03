#include <iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        int cnt=0;
        for (int i = 1; i <= n; i++)
        {
            int t = i;
            while (t)
            {
                if (t % 10 == 7)
                {
                    cnt++;
                    break;
                }
                t /= 10;
            }
        }
        cout << n - cnt << endl;
    }

    return 0;
}