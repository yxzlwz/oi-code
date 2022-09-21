#include <bits/stdc++.h>
using namespace std;

int n;

int F(string s) {
    int letters[26] = {0};
    for (auto c : s) letters[c - 'a']++;
    int jishu = 0;
    for (int i = 0; i < 26; i++)
        if (letters[i] % 2) jishu++;
    return jishu;
}

int main() {
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int len = s.length(), ans = 0;
        for (int i = 1; i < len; i++) {
            // printf("i: %d\n", i);
            string a = s.substr(0, i);
            for (int j = 1; i + j < len; j++) {
                // printf("j: %d\n", j);
                string b = s.substr(i, j);
                for (int k = 1; (i + j) * k < len; k++) {
                    // printf("k: %d\n", k);
                    string c = s.substr((i + j) * k);
                    if (F(a) > F(c)) continue;
                    int kk = k;
                    string ss = s.substr();
                    bool flag = true;
                    while (kk > 1) {
                        if (ss.substr(0, i + j) != ss.substr(i + j, i + j)) {
                            flag = false;
                            break;
                        }
                        kk--;
                        ss = ss.substr(i + j);
                    }
                    if (flag) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
