#include <bits/stdc++.h>
using namespace std;

int n, a[10001];

inline void read(int &x) {  // 快读，来自我的博客
    x = 0;
    short flag = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') flag = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    x *= flag;
}

int main() {
    int t;
    read(t);
    while (t--) {  // t组数据
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);  // 读入每一个数字

        a[2] /= __gcd(a[1], a[2]);
        for (int i = 3; i <= n; i++) {
            a[2] /= __gcd(a[i], a[2]);  // 不停除以两数的最大公约数
            if (a[2] == 1) break;  // 如果已经为整数则跳出
        }

        // 判断最后分子是否化为1
        if (a[2] == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}