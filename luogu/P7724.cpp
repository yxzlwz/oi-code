#include <iostream>
using namespace std;
int a[4], b[4];
int main()
{
    int ac = 0, bc = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            ac++;
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> b[i];
        if (b[i] == 0)
            bc++;
    }
    if (ac != bc)
        cout << "No";
    else if (ac == 3 || ac == 4 || ac == 2)
        cout << "Yes";
    else if (ac == 0)
    {
        if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3])
            cout << "Yes";
        else
            cout << "No";
    }
    else if (ac == 1)
    {
        int aa = 0, bb = 0;
        if (a[0])
            aa = aa * 10 + a[0];
        if (a[1])
            aa = aa * 10 + a[1];
        if (a[3])
            aa = aa * 10 + a[3];
        if (a[2])
            aa = aa * 10 + a[2];
        if (b[0])
            bb = bb * 10 + b[0];
        if (b[1])
            bb = bb * 10 + b[1];
        if (b[3])
            bb = bb * 10 + b[3];
        if (b[2])
            bb = bb * 10 + b[2];
        if (aa == bb)
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}