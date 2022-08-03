#include <bits/stdc++.h>
using namespace std;

int n, a[400001], l[400001], r[400001], cnt, trie[13000005][2], ans;

void insert(int x) {
    int p = 0;
    for (int i = 31; i >= 0; i--) {
        bool ch = x >> i & 1;
        if (!trie[p][ch]) trie[p][ch] = ++cnt;
        p = trie[p][ch];
    }
}

int find(int x) {
    int p = 0, an = 0;
    for (int i = 31; i >= 0; i--) {
        an <<= 1;
        bool ch = x >> i & 1;
        if (trie[p][!ch]) {
            an += 1;
            p = trie[p][!ch];
        } else
            p = trie[p][ch];
    }
    return an;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s ^= a[i];
        insert(s);
        l[i] = max(l[i - 1], find(s));
    }
    memset(trie, 0, sizeof(trie));
    cnt = s = 0;
    for (int i = n; i >= 1; i--) {
        s ^= a[i];
        insert(s);
        r[i] = max(r[i - 1], find(s));
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, l[i] + r[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
