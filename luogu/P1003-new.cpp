#include <bits/stdc++.h>
using namespace std;
int a[10001][4];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 4; j++) cin >> a[i][j];

    int a1, a2;
    cin >> a1 >> a2;

    for (int i = n; i >= 0; i--) {
        if (a1 >= a[i][0] && a1 <= a[i][0] + a[i][2] && a2 >= a[i][1] &&
            a2 <= a[i][1] + a[i][3]) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}