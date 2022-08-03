#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
    int a, b;
} a[100010];

bool cmp(node &x, node &y) {
    // 虽然证明时是小于等于即可，但是cmp千万不能用<=，上文说明了！
    return (x.a * x.b) < (y.a * y.b);
}

bool str_bigger(char x[], char y[]) {
    // 比较两个字符串类型的数字大小
    if (strlen(x) > strlen(y))
        return true;
    else if (strlen(x) < strlen(y))
        return false;
    else {
    	int len = strlen(x);
        for (int i = 0; i < len; i++)
            if (x[i] > y[i])
                return true;
            else if (x[i] < y[i])
                return false;
        return false;
    }
}

void to_string(int num, char *tmp) {
    // 将整数转换为字符串
    int cnt = 0;
    while (num) {
        tmp[cnt++] = num % 10 + '0';
        num /= 10;
    }
    tmp[cnt] = '\0';
    for (int i = 0; i < cnt / 2; i++) {
        swap(tmp[i], tmp[cnt - i - 1]);
    }
}

void mul(char xx[], char yy[], char *ans) {
    // 高精度乘法，ans为结果，xx为第一个数，yy为第二个数
    int lenx = strlen(xx), leny = strlen(yy);
    int x[10001], y[10001], z[10001];
    for (int i = 0; i < lenx; i++) x[lenx - i - 1] = xx[i] - '0';
    for (int i = 0; i < leny; i++) y[leny - i - 1] = yy[i] - '0';

    memset(z, 0, sizeof(z));
    for (int i = 0; i < lenx; i++) {
        for (int j = 0; j < leny; j++) {
            z[i + j] += x[i] * y[j];
            z[i + j + 1] += z[i + j] / 10;
            z[i + j] %= 10;
        }
    }
    int lenans = lenx + leny;
    while (z[lenans] == 0 && lenans) lenans--;

    for (int i = lenans; i >= 0; i--) ans[i] = z[lenans - i] + '0';
    ans[lenans + 1] = '\0';
}

void div(char a[], int b, char *ans) {
    // 高精度除法，ans为结果，a为被除数，b为除数
    int c[10001];
    memset(c, 0, sizeof(ans));
    int len = strlen(a);
    int k = 0;  // 每一位的余数
    for (int i = 0; i < len; i++) {
        c[i] = k * 10 + a[i] - '0';
        k = c[i] % b;
        c[i] /= b;
    }
    int i = 0;
    while (c[i] == 0 && i < len - 1) i++;
    for (int j = i; j < len; j++) ans[j - i] = c[j] + '0';
    ans[len - i] = '\0';
}

int main() {
    cin >> n >> a[0].a >> a[0].b;
    char t[100010];  // 每个大臣前面所有大臣左手上数字的积（包括国王）
    to_string(a[0].a, t);  // 将国王的左手上数字存入t
    char ans[100010];

    // 输入数据并排序
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b;
    }
    sort(a + 1, a + n + 1, cmp);

    // 开始遍历计算
    for (int i = 1; i <= n; i++) {
        // 计算当前大臣的钱数
        char tmp[100010];
        div(t, a[i].b, tmp);

        // 比较大小，决定是否存为ans
        if (str_bigger(tmp, ans)) {
            strcpy(ans, tmp);
        }

        // 将当前大臣左手的数字乘进t里面
        char tmp1[100010];
        to_string(a[i].a, tmp1);
        mul(t, tmp1, tmp);
        strcpy(t, tmp);
    }

    cout << ans << endl;

    return 0;
}