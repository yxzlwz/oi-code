#include <bits/stdc++.h>
using namespace std;

struct edge {
    int x, y, v;  // 起点、终点和权值
} a[10001];

int edges, tot;  // 边的数量、生成树中边的权值总和、已加入生成树的边数
int father[101];  // father[]用于并查集

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
    int n, k;
    cin >> n >> k;
    int temp;
    for (int i = 1; i <= k; i++) {
        cin >> a[i].x >> a[i].y >> a[i].v;
    }
    for (int i = 1; i <= n; i++) father[i] = i;  // 初始化并查集

    sort(a + 1, a + k + 1, cmp);  // 将所有的边按权值从小到大排序
    int ans = 0,cntt = 0;
    for (int i = 1; i <= k; i++) {
        if (check(a[i].x) != check(a[i].y)) {
            unionn(a[i].x, a[i].y);  // 合并两个独立的树
            tot += a[i].v;           // 总权值加上当前边
            cntt++;
            ans = max(a[i].v, ans);
            if(cntt == n - 1){
                break;
            }
        }
    }

    cout << n-1<<" "<<ans;

    return 0;
}