#include <bits/stdc++.h>
using namespace std;
int b[100001][100001];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m, n, o, p;
        cin >> m >> n >> o >> p;
        for (int j = 0; j < o; j++)
            for (int k = 0; k < p; k++) b[m + j][n + k] = i;
    }
    int a1, a2;
    cin >> a1 >> a2;
    cout << (b[a1][a2] ? b[a1][a2] : -1) << endl;

    return 0;
}