#include <bits/stdc++.h>
using namespace std;

int ch[100001][15], n, tot;
bool tags[100001];

int insert(char s[]) {
    int p = 0, len = strlen(s + 1);
    bool changed = 0;
    for (int i = 1; i <= len; i++) {
        s[i] -= '0';
        if (ch[p][int(s[i])] == -1) {
            ch[p][int(s[i])] = ++tot;
            changed = 1;
        }
        p = ch[p][int(s[i])];
        if (tags[p]) {
            return 1;
        }
    }
    tags[p] = 1;
    if (!changed) {
        return 1;
    } else
        return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(ch, -1, sizeof(ch));
        memset(tags, 0, sizeof(tags));
        tot = 0;
        char s[20];
        bool ok = 0;
        for (int i = 1; i <= n; i++) {
            cin >> (s + 1);
            if (ok) continue;
            if (insert(s)) {
                ok = 1;
            }
        }
        cout << (ok ? "NO" : "YES") << endl;
    }

    return 0;
}