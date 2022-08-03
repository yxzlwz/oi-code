#include <bits/stdc++.h>
using namespace std;
int a[10001];
int main() {
    // freopen("E:/Desktop/P1317_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i && a[i - 1] == a[i]) {
            i--, n--;  // https://www.luogu.com.cn/blog/Histone/solution-p1317
        }
    }
    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            count++;
        }
    }
    cout << count;

    return 0;
}