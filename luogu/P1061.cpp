#include <bits/stdc++.h>

#include <cstdio>
using namespace std;
int main() {
    int ss, tt, w;
    cin >> ss >> tt >> w;
    char s = 'a' - 1 + ss, t = 'a' - 1 + tt;
    char a[100];
    cin.getline(a, sizeof(a));
    cin.getline(a, sizeof(a));
    // cin.get(a);
    // gets(a);
    int len = strlen(a);
    for (int i = len - w; i < len; i++) a[i - len + w] = a[i];
    a[w] = '\0';

    bool have = 1;

    for (int k = 1; k <= 5 && have; k++) {
        have = 0;
        for (int i = w - 1; i >= 0; i--) {
            if (a[i] == t || (i != w - 1 && a[i] + 1 == a[i + 1])) continue;
            a[i]++;
            for (int j = i + 1; j < w; j++) {
                while (a[j] > a[j - 1] + 1) a[j]--;
            }
            have = 1;
            cout << a << endl;
            break;
        }
    }

    return 0;
}