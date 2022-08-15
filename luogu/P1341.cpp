#include <bits/stdc++.h>
using namespace std;
int g[601][601], cnt0, cnt[501], sum, f, minn = 100, minn1 = 100, asdf;
char ans[10000];
void dfs(int s) {
    for (int i = 0; i <= 100; i++) {
        if (g[s][i] >= 1) {
            g[s][i]--, g[i][s]--;
            dfs(i);
        }
    }
    ans[++cnt0] = s + 'A';
}
int main() {
    cin >> f;
    for (int i = 1; i <= f; i++) {
        string a;
        cin >> a;
        g[a[0] - 'A'][a[1] - 'A']++, g[a[1] - 'A'][a[0] - 'A']++;
        cnt[a[0] - 'A']++, cnt[a[1] - 'A']++;
    }
    for (int i = 0; i <= 100; i++) {
        if (cnt[i] % 2 == 1) {
            minn = min(minn, i);
            sum++;
        } else if (cnt[i] != 0)
            minn1 = min(minn1, i);
    }
    if (sum != 0 && sum != 2) {
        cout << "No Solution";
        return 0;
    } else if (sum == 2)
        dfs(minn);
    else
        dfs(minn1);
    for (int i = cnt0; i >= 1; i--) cout << ans[i];
    return 0;
}