#include <bits/stdc++.h>
using namespace std;
/*
    cnt0: 路径的长度
    cnt[i]: i点的度
    sum: 度为奇数的节点的个数
    n: 如题，要求的组数
    minn: 度为奇数的节点最小编号
    minn1: 度为偶数的节点最小编号
*/
int cnt0, cnt[101], sum, n, minn = 100, minn1 = 100;
bool g[101][101];
char ans[10000];
void dfs(int s) {
    for (int i = 0; i <= 100; i++) {
        if (g[s][i] >= 1) {
            g[s][i] = g[i][s] = 0;
            dfs(i);
        }
    }
    ans[++cnt0] = s + 'A';
}
int main() {
    cin >> n;
    while (n--) {
        char a, b;
        cin >> a >> b;
        a -= 'A', b -= 'A';
        g[a][b] = g[b][a] = 1;
        cnt[a]++, cnt[b]++;
    }
    for (int i = 0; i <= 100; i++) {
        if (cnt[i] % 2 == 1) {
            minn = min(minn, i);
            sum++;
        } else if (cnt[i] != 0)
            minn1 = min(minn1, i);
    }
    if (sum != 0 && sum != 2) {
        cout << "No Solution";
        return 0;
    } else if (sum == 2)
        dfs(minn);
    else
        dfs(minn1);
    for (int i = cnt0; i >= 1; i--) cout << ans[i];
    cout << endl;
    return 0;
}