#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[50], len, f[50][65], vis[50][65];
int dfs(bool limit, bool lead, int pos, int cha) {
    if (pos == 0) return cha >= 30;
    if (!limit && !lead && vis[pos][cha]) return f[pos][cha];
    int res = 0;
    int up = limit ? a[pos] : 1;
    for (int i = 0; i <= up; i++) {
        res += dfs(limit & (i == a[pos]), lead & (i == 0), pos - 1,
                   cha + (i == 0 ? (lead ? 0 : 1) : -1));
    }
    if (!limit && !lead) vis[pos][cha] = 1, f[pos][cha] = res;
    return res;
}
int solve(int x) {
    len = 0;
    while (x) {
        a[++len] = x % 2;
        x /= 2;
    }
    return dfs(1, 1, len, 30);
}
int main() {
    int l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1);
}