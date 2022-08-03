#include <bits/stdc++.h>
using namespace std;

int m, n, x, y;  // 层数，要删去的节点个数，所需的地图宽度，所需的地图高度
char mp[5000][10000];  // 存储最终打印的地图
int ltimes[100] = {0, 0, 1, 2, 5};
bool locker[100][100];  // 标记要被删去的节点，locker[i][j]=true表示第i层第j个的节点要被删去

void dfs(int p, int q, int level, int times, bool left, int num) {
    /*
        p, q: 当前节点的坐标
        level: 当前节点所在的树叶层层数（若当前为树枝层，则取上方最靠近的树叶层的值），用于确定所需的树枝层的数量
        times: 到目前level值未变动的递归层数，用于标记是否画完了当前所需的树枝层数
        left: 标记树枝层的延伸方向，值为true代表向左
        num: 在当前层当前节点的编号（表示第几个，用于确认是否要删除；仅当处于树叶层时有意义）
    */

   // 根据times判断是否到达树叶层
    if (times == 0) {
        // 是树叶层，进行相应标记
        mp[p][q] = 'o';

        // 判断当前节点是否要删除
        if (locker[level][num]) {
            // 删去节点
            mp[p][q] = ' ';

            // 判断该节点前树枝的延伸方向，原路返回删除树枝，直到到达上一个树叶层
            if (left) {
                for (int i = p - 1, j = q + 1; mp[i][j] != 'o'; i--, j++) {
                    mp[i][j] = ' ';
                }
            } else {
                for (int i = p - 1, j = q - 1; mp[i][j] != 'o'; i--, j--) {
                    mp[i][j] = ' ';
                }
            }

            // 删除完成后停止该子树的递归
            return;
        }

        // 如果当前已经到达了最底的树叶层，则停止递归
        if (level == m) return;

        // 如果当前节点无需删除且不是最底的树叶层，则继续递归，分为左右子树分别处理
        // 当前节点在当前层的编号，乘2减1得其左孩子在左孩子所在层的编号，乘2得其右孩子在右孩子所在层的编号
        dfs(p + 1, q - 1, level, times + 1, true, num * 2 - 1);
        dfs(p + 1, q + 1, level, times + 1, false, num * 2);
    } else {
        // 是树枝层，进行相应标记
        mp[p][q] = left ? '/' : '\\';

        // 判断是否是当前这一组树枝层的最后一层
        if (times == ltimes[m + 1 - level]) {
            // 是，则下一层level+1，times=0
            if (left)
                dfs(p + 1, q - 1, level + 1, 0, true, num);
            else
                dfs(p + 1, q + 1, level + 1, 0, false, num);
        } else {
            // 不是，正常递归，除坐标外仅需处理times
            if (left)
                dfs(p + 1, q - 1, level, times + 1, true, num);
            else
                dfs(p + 1, q + 1, level, times + 1, false, num);
        }
    }
}

int main() {
    memset(mp, ' ', sizeof(mp));  // 地图赋初始值为' '
    for (int i = 3; i < 100; i++) {
        ltimes[i] = 3 * pow(2, i - 3) - 1;  // 初始化树叶层之间树枝层的数量
    }

    // 数据输入，并确定地图大小（找规律，具体公式上文说了）
    cin >> m >> n;
    if (m == 1) {
        x = 1;
        y = 1;
    } else {
        x = 6 * pow(2, m - 2) - 1;
        y = 3 * pow(2, m - 2);
    }

    // 根据输入的数据，确定要删除的节点，记录在locker中
    int t1, t2;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        locker[t1][t2] = true;
    }

    // 根据地图大小确定根节点位置，调用dfs函数画出地图
    // 易知根节点处于第1行，列数为x/2+1（因为其处于第一行正中的对称轴上，x恒为奇数）
    dfs(1, x / 2 + 1, 1, 0, 0, 1);

    // 打印地图，由于x表示的是宽度，即列数，所以外层为y内层为x
    for (int i = 1; i <= y; i++) {
        for (int j = 1; j <= x; j++) {
            cout << mp[i][j];
        }
        cout << endl;
    }

    return 0;
}