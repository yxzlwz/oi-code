#include <bits/stdc++.h>
using namespace std;

long long p;

long long ksm(long long m, long long n) {
    if (n == 1) return m;
    if (n == 0) return 1;
    long long k = ksm(m, n / 2) % p;
    if (n % 2 == 0)
        return k * k % p;
    else
        return k * k % p * m % p;
}

int main() {
    long long a, b, ans;
    cin >> a >> b >> p;
    ans = ksm(a % p, b) % p;
    printf("%ld^%ld mod %d=%ld", a, b, p, ans);

    return 0;
}
