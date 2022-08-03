#include <bits/stdc++.h>
using namespace std;

char s[100000];

int main() {
    int p1, p2, p3, none;
    cin >> p1 >> p2 >> p3;
    gets(s);
    gets(s);
    int i = 1;
    while (i < strlen(s)) {
        if (s[i] == '-') {
            if (s[i - 1] >= s[i + 1] || (s[i - 1] == '-' || s[i + 1] == '-')) {
                none = 0;
            } else if (((s[i - 1] >= '0' && s[i - 1] <= '9') &&
                        ((s[i + 1] >= 'A' && s[i + 1] <= 'Z') ||
                         (s[i + 1] >= 'a' && s[i + 1] <= 'z'))) ||
                       ((s[i + 1] >= '0' && s[i + 1] <= '9') &&
                        ((s[i - 1] >= 'A' && s[i - 1] <= 'Z') ||
                         (s[i - 1] >= 'a' && s[i - 1] <= 'z')))) {
                none = 0;
            } else if (s[i - 1] == s[i + 1] - 1) {
                int len = strlen(s);
                for (int j = i + 1; j < len; j++) s[j - 1] = s[j];
                s[len - 1] = '\0';
            } else if (s[i - 1] < s[i + 1]) {
                if (s[i - 1] >= '0' && s[i - 1] <= '9') {
                    int len = strlen(s);
                    int llen = (s[i + 1] - s[i - 1] - 1) * p2;
                    for (int j = len; j > i; j--) s[j + llen - 1] = s[j];
                    char c = s[i - 1] + 1;
                    if (p1 == 3) c = '*';
                    for (int j = i; j < i + llen;) {
                        for (int k = 0; k < p2; k++, j++) s[j] = c;
                        if (p1 != 3) c++;
                    }
                    if (p3 == 2) reverse(s + i, s + i + llen);
                    s[len + llen] = '\0';
                    // for(int j = 0; j < 10; j++){
                    //     printf("%d:%d ", j, int(s[j]));
                    // }
                    // cout << endl;
                } else {
                    int len = strlen(s);
                    int llen = (s[i + 1] - s[i - 1] - 1) * p2;
                    for (int j = len; j > i; j--) s[j + llen - 1] = s[j];
                    char c;
                    if (p1 == 3)
                        c = '*';
                    else if (s[i - 1] >= 'A' && s[i - 1] <= 'Z') {
                        if (p1 == 1)
                            c = s[i - 1] + 1 + 32;
                        else
                            c = s[i - 1] + 1;
                    } else {
                        if (p1 == 1)
                            c = s[i - 1] + 1;
                        else
                            c = s[i - 1] + 1 - 32;
                    }
                    for (int j = i; j < i + llen;) {
                        for (int k = 0; k < p2; k++, j++) s[j] = c;
                        if (p1 != 3) c++;
                    }
                    if (p3 == 2) reverse(s + i, s + i + llen);
                    s[len + llen] = '\0';
                }
            }
        }
        i++;
        if (i == strlen(s)) break;
    }

    cout << s;

    return 0;
}