#include <bits/stdc++.h>
using namespace std;

int g[5001][5001];  // 存放邻接矩阵
// minn[i]存放未加入最小生成树的点与任意已加入生成树的点路径权值的最小值
int minn[5001];
bool u[5001];  // u[i]=true表示i已加入生成树

int main() {
    int n, m;
    memset(minn, 0x7f7f7f7f, sizeof(minn));  // 初始化为最大值
    memset(g, 0x7f7f7f7f, sizeof(g));        // 初始化为最大值
    minn[1] = 0;  // 起点赋0值，即默认从起点开始

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z < g[x][y]) g[x][y] = g[y][x] = z;  // 无向图输入
    }

    for (int i = 1; i <= n; i++) {
        int k = 0;
        for (int j = 1; j <= n; j++) {
            if (!u[j] && (minn[j] < minn[k])) k = j;
        }
        u[k] = true;  // k加入最小生成树
        if (k == 0) {
            // 整个过程一直没有找到路径，但是点还没有加入完，说明图不连通
            cout << "orz";
            return 0;
        }

        for (int j = 1; j <= n; j++) {
            // 未加入最小生成树且与新加入的k点相邻的点，通过g[k][j]更新minn[j]
            if (!u[j] && (g[k][j] < minn[j])) minn[j] = g[k][j];
        }
    }

    int tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += minn[i];
    }
    cout << tot;

    return 0;
}