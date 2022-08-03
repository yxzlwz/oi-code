#include <bits/stdc++.h>
using namespace std;

int n, ch[1000010][30], fail[1000010], cnt, endd[1000010];
char t[1000001];

void insert(char *s) {
    int p = 0, len = strlen(s + 1);
    for (int i = 1; i <= len; i++) {
        int a = s[i] - 'a';
        if (!ch[p][a]) ch[p][a] = ++cnt;
        p = ch[p][a];
    }
    endd[p]++;
}

void buildf() {
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        // fail[ch[0][i]] = 0;
        if (ch[0][i]) q.push(ch[0][i]);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (ch[x][i]) {
                fail[ch[x][i]] = ch[fail[x]][i];
                q.push(ch[x][i]);
            } else {
                ch[x][i] = ch[fail[x]][i];
            }
        }
    }
}

int search() {
    int p;
    int ans;
    ans = p = 0;
    int len = strlen(t + 1);
    // cout << len << endl;
    for (int i = 1; i <= len; i++) {
        int a = t[i] - 'a';
        p = ch[p][a];
        for (int j = p; j && endd[j] != -1; j = fail[j]) {
            ans += endd[j];
            endd[j] = -1;
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    char s[1000010];
    while (n--) {
        scanf("%s", s + 1);
        insert(s);
    }
    scanf("%s", t + 1);

    buildf();
    printf("%d\n", search());
    return 0;
}
