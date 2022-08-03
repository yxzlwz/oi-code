#include <bits/stdc++.h>
using namespace std;

int n, m, trie[1000005][2], cnt, len;
int endd[1000005], pass[1000005];
bool c[10001];

void insert() {
    int p = 0;
    for (int i = 1; i <= len; i++) {
        if (!trie[p][c[i]]) trie[p][c[i]] = ++cnt;
        p = trie[p][c[i]];
        pass[p]++;
    }
    endd[p]++;
}

int search() {
    int p = 0, an = 0;
    for (int i = 1; i <= len; i++) {
        if (!trie[p][c[i]]) return an;
        p = trie[p][c[i]];
        an += endd[p];
    }
    return an + pass[p] - endd[p];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> len;
        for (int j = 1; j <= len; j++) {
            cin >> c[j];
        }
        insert();
    }
    for(int i = 1; i <= m; i++) {
        cin >> len;
        for (int j = 1; j <= len; j++) {
            cin >> c[j];
        }
        cout << search() << endl;
    }
}
