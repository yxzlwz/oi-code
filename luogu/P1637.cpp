#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e4 + 10;
int n, a[N];

void read(int &a) {
    a = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        a = a * 10 + c - '0';
        c = getchar();
    }
}

signed main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }
    int ans = 0;
    int l, r;
    for (int i = 2, j; i < n; i++) {
        l = r = 0;
        for (j = 1; j < i; j++) {
            if (a[j] < a[i]) l++;
        }
        for (j = i + 1; j <= n; j++) {
            if (a[j] > a[i]) r++;
        }
        ans += l * r;
    }
    cout << ans;
}