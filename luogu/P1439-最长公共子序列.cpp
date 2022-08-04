#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int n, a[N], b[N], num_at_b[N], dp[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        num_at_b[b[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = num_at_b[a[i]];
        /*
        如果不将情况局限于此题，即对于 a 中的一个元素可能在 b 中存在多个
        那么 num_at_b 数组的类型就不能是 int ，而是 vector<int>
        此处我们也需要建立一个 vector<int> aa 来存储 a 中的元素在 b 中出现的每个位置
        举个例子： a = {1, 2}, b = {1, 2, 2, 1}
        则 num_at_b = {1: {1, 4}, 2: {2, 3}} （此处使用 Python 字典格式描述）
        aa = {(4, 1), (3, 2), (3, 2), (4, 1)} （圆括号实际上不存在，只是为了方便大家看）
        至于为什么要倒序存储，是为了保证在求解最长上升子序列时，每个元素只选到自己一次
        参考链接：https://blog.51cto.com/karsbin/966387
        */
    }

    int len = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (dp[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, r + 1);
        dp[r + 1] = a[i];
    }
    cout << len;
}
