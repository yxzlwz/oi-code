#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull power[1000001], b = 131;
ull sum[1000001];
char s1[10001], s2[1000001];

int main() {
    power[0] = 1;
    for (int i = 1; i <= 1000000; i++) power[i] = power[i - 1] * b;
    int T;
    cin >> T;
    while (T--) {
        scanf("%s%s", s1 + 1, s2 + 1);
        int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
        sum[0] = 0;
        for (int i = 1; i <= len2; i++)
            sum[i] = sum[i - 1] * b + (ull)(s2[i] - 'A' + 1);
        ull s = 0;
        for (int i = 1; i <= len1; i++) {
            s = s * b + ull(s1[i] - 'A' + 1);
        }
        int ans = 0;
        for (int i = 0; i <= len2 - len1; i++) {
            if (s == sum[i + len1] - sum[i] * power[len1]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}