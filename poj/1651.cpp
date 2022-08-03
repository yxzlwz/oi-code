#include <algorithm>
#include <iostream>
using namespace std;

const int N = 501;
int f[N][N], n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i < n; i++) {
        for (int j = 1; j + i <= n; j++) {
            f[j][j + i] = 0x3f3f3f3f;
            for (int k = j + 1; k <= j + i - 1; k++) {
                f[j][j + i] = min(f[j][j + i], f[j][k] + f[k][j + i] +
                                                   a[j] * a[k] * a[j + i]);
            }
        }
    }
    cout << f[1][n] << endl;
}