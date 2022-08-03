#include <bits/stdc++.h>
using namespace std;
double s1 = 0, c1 = 0, s2 = 0, c2 = 0;
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {
            c1++;
            s1 += i;
        } else {
            c2++;
            s2 += i;
        }
    }
    printf("%.1f %.1f", s1 / c1, s2 / c2);

    return 0;
}