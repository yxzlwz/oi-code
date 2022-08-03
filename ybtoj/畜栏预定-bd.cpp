#include <bits/stdc++.h>
using namespace std;

const int N = 50100;
int n;
struct cow {
    int l, r;
    int id;  // 牛原来的编号
    bool operator<(const cow a) const {
        return l < a.l;  // 按开始吃草的时间从小到大排序
    }
} a[N];

int ans[N];
struct Node {
    int r;
    int id;
    Node(int a, int b) {
        r = a;
        id = b;
    }
    bool operator<(const Node a) const {
        return a.r < r;  // 维护结束吃草时间的大根堆
    }
};

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r, a[i].id = i;
    sort(a + 1, a + 1 + n);
    priority_queue<Node> q;

    for (int i = 1; i <= n; i++) {
        if (!q.size() || q.top().r >= a[i].l)  // 新建畜栏
        {
            ans[a[i].id] = q.size() + 1;
            q.push((Node){a[i].r, ans[a[i].id]});
        } else  // 找到可行畜栏
        {
            ans[a[i].id] = q.top().id;
            q.pop();
            q.push((Node){a[i].r, ans[a[i].id]});
        }
    }
    cout << q.size() << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;

    return 0;
}