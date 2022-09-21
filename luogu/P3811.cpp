#include <cstdio>
#define int long long
using namespace std;

int ink[3000005];

signed main() {
    int n, p;
    scanf("%lld %lld", &n, &p);
    ink[1] = 1;
    puts("1");
    for (int i = 2; i <= n; i++) {
        ink[i] = (p - p / i) * ink[p % i] % p;
        printf("%lld\n", ink[i]);
    }
}