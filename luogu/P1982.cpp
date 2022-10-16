#include <bits/stdc++.h>
#define int __int128
using namespace std;

const int N = 1000001;

void read(int &x) {
    int f = 1;
    x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int n, p, a, b[N], c;

signed main() {
    read(n), read(p);
    read(a);
    b[1] = a;
    int mm = b[1], last = b[1];
    for (int i = 2; i <= n; i++) {
        // 读入当前数字，由于处理好特征值之后不会再用，所以不用数组
        read(a);
        // 此处的 b[i] 是到 i 结尾的最大子段和
        b[i] = max(last + a, a);
        // 维护 last 为“到 i - 1 结尾的最大子段和”
        last = b[i];
        // mm 是区间 [1, i] 的最大子段和
        mm = max(b[i], mm);
        // 此处 b[i] 变成了第 i 个小朋友的特征值
        b[i] = mm;
    }
    // 结束 for 循环后，b[i] 为 i 的特征值

    // 存储当前最大分数，也是整个程序所求结果
    int fenshu_max = c = b[1];
    int fenshu_and_special_max = c + b[1];
    for (int i = 2; i <= n; i++) {
        c = fenshu_and_special_max;
        fenshu_and_special_max = max(fenshu_and_special_max, c + b[i]);
        fenshu_max = max(fenshu_max, c);
    }

    // 输出要求：所有小朋友分数的最大值；
    // 输出时保持最大值的符号，将其绝对值对 p 取模后输出
    // 注意！出于此要求，不能在前方程序中取模
    if (fenshu_max < 0) {
        putchar('-');
        fenshu_max = -fenshu_max;
    }
    fenshu_max %= p;
    write(fenshu_max);
    putchar('\n');

    return 0;
}