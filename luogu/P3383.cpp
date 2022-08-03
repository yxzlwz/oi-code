#include <bits/stdc++.h>
using namespace std;

int ss[100000001], cnt;  // ss: ss[i]表示第i个素数，cnt: ss的长度，即素数的个数
bool pd[100000001];  // pd: pd[i]表示i是否是素数

inline void read(int &x){  // 快读不说了
    x = 0;
    short fs = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')fs = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = x * 10 + c - '0';
        c = getchar();
    }
    x *= fs;
}

int main() {
    memset(pd, 1, sizeof(pd));  // 默认都是素数，一个一个筛出去
    pd[0] = pd[1] = 0;  // 0和1不是素数（其实不处理也无所谓不影响本题结果）
    int n, q, k;
    read(n);
    read(q);

    // 重点筛数的过程！！！
    for (int i = 2; i <= n; i++) {
        if (pd[i]) ss[++cnt] = i;  // 如果到了这一步仍没有筛掉i，说明i是素数，把它放入素数列表ss
        for (int j = 1; j <= cnt && ss[j] * i <= n; j++) {  // ①
            pd[ss[j] * i] = 0;  // (ss[j] * i)肯定是合数，所以把它标记好
            if(i % ss[j] == 0) break;  // ②
        }
    }

    while(q--){
        // q次询问，输出第k个素数
        read(k);
        printf("%d\n", ss[k]);
    }

    return 0;
}