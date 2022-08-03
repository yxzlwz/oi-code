#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);

    while (n--) {
        int a;
        scanf("%d", &a);
        ans = gcd(ans, abs(a));
    }
    cout << ans;

    return 0;
}