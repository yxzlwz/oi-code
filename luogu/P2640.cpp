#include <iostream>
using namespace std;
bool ss[10001] = {0, 0, 1};
int main()
{
    for (int i = 3; i <= 10000; i += 2)
    {
        bool sss = 1;
        for (int j = 3; j < i / 2 + 1; j++)
            if (i % j == 0)
            {
                sss = 0;
                break;
            }
        ss[i] = sss;
    }
    int n, k;
    cin >> n >> k;
    bool outed = 0;
    for (int i = 2; i <= n - k; i++)
    {
        if (!ss[i] || !ss[i + k])
            continue;
        cout << i << " " << i + k << endl;
        outed = 1;
    }
    if (!outed)
        cout << "empty";
    return 0;
}