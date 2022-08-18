#include <bits/stdc++.h>
using namespace std;

int n, q, trie[3000005][65], cnt, pass[3000005];

inline int getnum(char x) {
    if (x >= 'A' && x <= 'Z')
        return x - 'A';
    else if (x >= 'a' && x <= 'z')
        return x - 'a' + 26;
    else
        return x - '0' + 52;
}

void insert(string s) {
    int cur = 0, len = s.length();
    for (int i = 0; i < len; i++) {
        int a = getnum(s[i]);
        if (!trie[cur][a]) trie[cur][a] = ++cnt;
        cur = trie[cur][a];
        pass[cur]++;
    }
}

int check(string t) {
    int cur = 0, len = t.length();
    for (int i = 0; i < len; i++) {
        int a = getnum(t[i]);
        cur = trie[cur][a];
        if (!cur) return 0;
    }
    return pass[cur];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i <= cnt; i++)
            for (int j = 0; j < 65; j++) trie[i][j] = 0;
        for (int i = 0; i <= cnt; i++) pass[i] = 0;
        cnt = 0;

        cin >> n >> q;
        while (n--) {
            string s;
            cin >> s;
            insert(s);
        }
        while (q--) {
            string t;
            cin >> t;
            cout << check(t) << endl;
        }
    }
}