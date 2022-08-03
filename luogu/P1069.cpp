#include <bits/stdc++.h>
using namespace std;

int n;
int m1, m2, s[10001];
int zs[30010][3] = {{2, 0, 0}}, czs = 1;


int main() {
    for (int i = 3, is; i < 30020; i += 2) {
        is = 1;
        for (int j = 0; j < czs; j++) {
            if (!i % zs[j][0]) {
                is = 0;
                break;
            }
        }
        if (is) {
            zs[czs++][0] = i;
        }
    }

    cin >> n >> m1 >> m2;
    for (int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n)

    for (int i = 0; i < n; i++) {
        if (__gcd(m1, s[i]) > 1) break;
        if (i == n - 1) cout << -1;
        return 0;
    }

    for (int j = 1;; j++) {
        for (int i = 0; i < n; i++)
            if (!ksm(s[i], j, pow(m1, m2))) {
                cout << j;
                return 0;
            }
    }

    return 0;
}