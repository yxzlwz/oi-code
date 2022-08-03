#include <bits/stdc++.h>
using namespace std;

int n, a[11], cnt;

void dfs(int i, int tot, bool flag) {
    if (i == 11) {
        if (tot == n) {
            if (flag) {
                for (int j = 1; j < 10; j++) cout << a[j] << " ";
                cout << a[10] << endl;
            } else
                cnt++;
        }
        return;
    }
    if (tot > n || i > 10) return;
    for (int j = 1; j <= 3; j++) {
        a[i] = j;
        dfs(i + 1, tot + j, flag);
    }
}

int main() {
    cin >> n;
    dfs(1, 0, 0);
    cout << cnt << endl;
    dfs(1, 0, 1);
}