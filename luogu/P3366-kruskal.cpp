#include <bits/stdc++.h>
using namespace std;

struct edge {
    int x, y, v;  // 起点、终点和权值
} a[500001];

int edges, tot, k;  // 边的数量、生成树中边的权值总和、已加入生成树的边数
int father[5001];  // father[]用于并查集

int check(int x) {
    // 并查集查找操作
    if (father[x] != x)
        return father[x] = check(father[x]);
    else
        return x;
}

int unionn(int x, int y) {
    // 并查集合并操作
    x = check(x);
    y = check(y);
    father[y] = x;
}

bool cmp(edge p, edge q) {
    // sort按照边权值从小到大为a排序的自定义比较函数
    return p.v < q.v;
}

int main() {
    int n, m;
    cin >> n >> m;
    int t1, t2, t3;
    while (m--) {
        // 由于随后要进行排序，因此此处无需判断t1,t2两点间是否已存在更短的路径
        cin >> t1 >> t2 >> t3;
        a[++edges].x = t1;
        a[edges].y = t2;
        a[edges].v = t3;
    }
    for (int i = 1; i <= n; i++) father[i] = i;  // 初始化并查集

    sort(a + 1, a + edges + 1, cmp);  // 将所有的边按权值从小到大排序

    for (int i = 1; i <= edges; i++) {
        if (check(a[i].x) != check(a[i].y)) {
            unionn(a[i].x, a[i].y);  // 合并两个独立的树
            tot += a[i].v;           // 总权值加上当前边
            k++;                     // 边数
            if (k == n - 1) {
                // 最小生成树有n-1条边，因此 k == n - 1 即程序完成
                break;
            }
        }
    }

    if (k == n - 1)
        cout << tot;
    else
        cout << "orz";

    return 0;
}