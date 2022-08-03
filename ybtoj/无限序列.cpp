#include <bits/stdc++.h>
using namespace std;
const int N = 110;
long long sizef[N], num1[N];  // sizef: 序列长度，num1: 1的个数

inline long long solve(long long v) {
    if (!v) return 0;  // 边界条件，递归出口
    int maxx = 0;      // 记录位置

    for (int i = 90; i >= 1; i--) {
        if (sizef[i] <= v) {
            // 找到最长的序列
            maxx = i;
            break;
        }
    }

    // 将长度sizef[maxx]减去后继续递归求解
    return num1[maxx] + solve(v - sizef[maxx]);
}

int main() {
    num1[1] = sizef[1] = 1, num[2] = sizef[2] = 2;
    for (int i = 3; i <= 90; i++) {
        sizef[i] = sizef[i - 1] + sizef[i - 2];
        num1[i] = num1[i - 1] + num1[i - 2];
    }
    int q;
    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        printf("%lld\n", solve(r) - solve(l - 1));
    }
    return 0;
}