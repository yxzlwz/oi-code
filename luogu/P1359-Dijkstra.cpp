#include <bits/stdc++.h>
using namespace std;

int g[201][201];  // 邻接矩阵
int dis[201];     // dis[i]表示从起点到i的最短路径
bool book[201];


int main() {
    memset(g, 0x7f7f7f7f, sizeof(g));

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }

    book[1] = true;
    for (int i = 2; i <= n; i++) {
        dis[i] = g[1][i];
    }

    for (int i = 1; i <= n - 1; i++) {
        int minnum = 0x7f7f7f7f, u;
        for (int j = 1; j <= n; j++) {
            if (!book[j] && dis[j] < minnum) {
                // 在没有闭环的情况下，当前距离已经最短的点不可能更短了
                minnum = dis[j];
                u = j;
            }
        }
        book[u] = true;
        for (int v = 1; v <= n; v++) {
            if (g[u][v] < 0x7f7f7f7f && dis[v] > dis[u] + g[u][v]) {
                dis[v] = dis[u] + g[u][v];
            }
        }
    }

    cout << dis[n];

    return 0;
}