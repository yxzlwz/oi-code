#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
long long s, b, p;
long long fpow(long long a, long long x) {
    long long ans = 1;
    for (long long now = a; x; x >>= 1, now = now * now % s) {
        // cout<<x<<endl;
        if (x & 1) {
            ans *= now;
            ans %= s;
        }
    }
    return ans;
}
int main() {
    scanf("%lld%lld%lld", &b, &p, &s);
    cout << b << "^" << p << " mod " << s << "=" << fpow(b, p) % s;
    return 0;
}
// 4523 59 7762