#include <bits/stdc++.h>
using namespace std;

struct node {
    int a, b;
} m[1000001];

int n;

bool cmp(node x, node y) { return x.b < y.b; }

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> m[i].a >> m[i].b;
    sort(m + 1, m + n + 1, cmp);
    int cnt = 0, last_stop = -1;
    for (int i = 1; i <= n; i++) {
        if (m[i].a >= last_stop) {
            cnt++;
            last_stop =m[i].b;
        }
    }
    cout << cnt << endl;

    return 0;
}