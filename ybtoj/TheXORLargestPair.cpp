#include <bits/stdc++.h>
using namespace std;

int n, t, cnt, trie[4000005][2], ans;

void insert(int x){
    int p = 0;
    for(int i = 31; i >= 0; i--){
        bool ch = (x >> i) & 1;
        if(!trie[p][ch]) trie[p][ch] = ++cnt;
        p = trie[p][ch];
    }
}

int search(int x) {
    int p = 0, an = 0;
    for (int i = 31; i >= 0; i--) {
        an <<= 1;
        bool ch = (x >> i) & 1;
        if (trie[p][!ch])
            p = trie[p][!ch], an = an | 1;
        else
            p = trie[p][ch];
    }
    return an;
}

int main() {
    cin >> n;
    while (n--) {
        cin >> t;
        ans = max(ans, search(t));
        insert(t);
    }
    cout << ans;
    return 0;
}
