#include <iostream>
#include <iomanip>
using namespace std;
int a[101][101];
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = -1;
        }
    }
    int mv = 0, i = 1, x = 1, y = 1;
    while (i <= n * n)
    {
        a[x][y] = i;
        if (a[x + d[mv % 4][0]][y + d[mv % 4][1]] != -1)
        {
            mv++;
        }
        x += d[mv % 4][0];
        y += d[mv % 4][1];
        i++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }

    return 0;
}