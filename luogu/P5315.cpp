#include <iostream>
using namespace std;
int main()
{
    int n, l, g, w, h;
    cin >> n >> l >> g;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> h;
        while (w > g || h > g)
        {
            w /= 2;
            h /= 2;
        }
        if (w < l || h < l)
            cout << "Too Young\n";
        else if (w != h)
            cout << "Too Simple\n";
        else
            cout << "Sometimes Naive\n";
    }

    return 0;
}