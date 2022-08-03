#include <bits/stdc++.h>
using namespace std;

int n, cnt;
char m[10001];

int b = 131;
const unsigned long long mod = 212370440130137957;
set<unsigned long long> s;

int main() {
    cin >> n;
    while (n--) {
        cin >> m;
        int len = strlen(m);
        unsigned long long h = 0;
        for (int i = 0; i < len; i++) {
            h = (h * b + m[i]) % mod;
        }
        if (!s.count(h)) {
            s.insert(h);
            cnt++;
        }
    }
    cout << cnt << endl;
}