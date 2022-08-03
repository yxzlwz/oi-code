#include <bits/stdc++.h>
using namespace std;
const int mod = 9901;
int ys[50000000];

// 一个不那么简单的快速幂模板
long long ksm(long long x, long long y) {
    if (y == 0) return 1;
    if (y % 2 == 0) return ((long long)pow(ksm(x, y / 2) % mod, 2) % mod);
    return (x * (long long)pow(ksm(x, y / 2) % mod, 2) % mod);
}

int main() {
    int a, b;
    cin >> a >> b;
    int aa = a;  // 由于aa的值会被修改，所以需要一个变量保存

    ys[2] = 0;
    while (a % 2 == 0) {
        a /= 2;
        ys[2]++;
    }
    ys[2] *= b;  // 因为是b次幂因此要乘以b
    for (int i = 3; i <= a / i; i += 2) {
        ys[i] = 0;
        while (a % i == 0) {
            a /= i;
            ys[i]++;
        }
        ys[i] *= b;
    }
    if(a != 1) {
        // 分解质因数，若有质因数超过根号a，则只能是a本身
        ys[a] = b;
    }

    long long ans = 1;
    for (int i = 2; i <= aa; i++) {
        if (!ys[i]) continue;  // 不存在该质因数
        int temp;
        if (i % mod == 1) {
            temp = (ys[i] + 1) % mod;  // 详见博文最后的解释
        } else
            temp = ((ksm(i, ys[i] + 1) - 1 + mod) % mod) * ksm(i - 1, mod - 2) % mod;  // 使用费马小定理求解
        if (temp != 0) ans = ans * temp % mod;
    }
    cout << ans << endl;

    return 0;
}
