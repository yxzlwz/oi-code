#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long ans = 1;
    // for (int i = n + 2, j = n + n; i <= j; i++) ans *= i;
    // for (int i = 2; i <= n; i++) ans /= i;

    for (int i = n + 2, j = n + n; i <= j; i++) {
        ans *= i;
        ans /= (i - n);
    }

    cout << ans;

    return 0;
}