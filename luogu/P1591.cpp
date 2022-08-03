#include <bits/stdc++.h>
using namespace std;

short num[1000001];

int main() {
    int tt, n, a, len = 1, jw, cnt;
    long long ans;
    cin >> tt;
    while (tt--) {
        memset(num, 0, sizeof(num));
        num[0] = 1;
        len = 1;  // ！
        cin >> n >> a;
        for (int j = 2; j <= n; j++) {
            jw = 0;
            for (int i = 0; i < len; i++) {
                num[i] = num[i] * j + jw;
                jw = num[i] / 10;
                num[i] %= 10;
            }
            while (jw) {  // 加法这里可以用if，乘法进位可能很多必须while
                num[len++] = jw % 10;
                jw /= 10;
            }
        }
        cnt = 0;
        for (int i = 0; i < len; i++)
            if (num[i] == a) cnt++;
        cout << cnt << endl;
    }
}