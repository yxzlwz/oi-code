#include <bits/stdc++.h>
using namespace std;

const int N = 25001;

int n, a[N], f[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int t;
            cin >> t;
            a[i] = t;
            f[a[i]] = 2;
        }
        // f[0] = 1;
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = a[i]; j <= a[n]; j++) {
                if (f[j - a[i]]) f[j] = 1;
            }
        }
        int cnt = 0;
        // for (int i = 1; i <= n; i++) {
        //     if (f[a[i]] == 2) cnt++;
        // }
        for (int i = 1; i <= a[n]; i++) {
            if (f[i] == 2) cnt++;
        }
        cout << cnt << endl;
    }
}
