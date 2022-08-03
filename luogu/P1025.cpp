#include <iostream>
using namespace std;

int dfs(int n, int k) {
    // 用k个数组成n，即把n分成k份
    if (n < k)  // 由于不能有0，所以n无法分成k（k > n）份
        return 0;
    else if (n == k || k == 1)  // 每组都是1或只有1组，无需继续递归
        return 1;
    else
        return dfs(n - 1, k - 1) + dfs(n - k, k);
        // k个数至少一个为1的方案数 + 全部不为1的方案数（见下方文字详解）
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << dfs(n, k);

    return 0;
}