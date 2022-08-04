// https://www.acwing.com/solution/content/23960/

#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int n, a[N];
int q[N];  // q[i]=a 表示长度为 i 的最长子序列的最后一个元素的值最小是 a

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int len = 0;  // 最开始找到的最长子序列长度为 0
    q[0] = INT_MIN;
    for (int i = 1; i <= n; i++) {  // 遍历每个元素
        int l = 0, r = len;
        while (l < r) {
            // 二分寻找满足 q[j] < a[i] 的 j 的最大值
            int mid = (l + r + 1) >> 1;  // 玄学问题需要 +1，知道的话帮忙解释下
            if (a[i] > q[mid])
                l = mid;
            else
                r = mid - 1;
        }
        // q[r] < a[i]，所以 r + 1 是新找到的最长子序列的长度
        // 又因为 q[r + 1] >= a[i]，所以此处直接更新 q[r + 1]
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }
    cout << len << endl;
}