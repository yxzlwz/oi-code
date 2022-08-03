// https://www.luogu.com.cn/problem/P3367

#include <bits/stdc++.h>
using namespace std;

int f[10001];

// 递归解法
// int find(int a) {
//     if (f[a] != a) {
//         // 路径压缩：一棵深度大的树变成宽度大的树，减少递归
//         return f[a] = find(f[a]);
//     } else {
//         return a;
//     }
// }

// 循环解法
int find(int a) {
    // a是要查询的节点，ans是返回的结果
    int ans = a;
    while (f[ans] != ans) {
        // 循环寻找a的父节点，直到找到树根
        ans = f[ans];
    }
    int i;
    while (f[a] != a) {
        // 将途径节点的父节点全部刷新为树根
        i = a;  // 暂存当前节点，以保证更改a后仍能找回当前选择的节点
        a = f[a];    // 下一个要操作的节点编号
        f[a] = ans;  // 当前节点的父节点直接更新为树根
    }
    return ans;
}

int hb(int a, int b) { f[find(b)] = find(a); }

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i;

    int z, x, y;
    while (m--) {
        cin >> z >> x >> y;
        if (z == 1) {
            hb(x, y);
        } else {
            if (find(x) == find(y))
                cout << "Y\n";
            else
                cout << "N\n";
        }
    }

    return 0;
}