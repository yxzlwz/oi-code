#include <bits/stdc++.h>
using namespace std;

const int mod = 100003;

int a[100001];

int main() {
    int n, k;
    cin >> n >> k;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = max(1, i - k); j <= i - 1; j++) {
            a[i] += a[j];
            a[i] %= mod;
        }
        if (i <= k) a[i] += 1;
        a[i] %= mod;
    }
    cout << a[n];
}