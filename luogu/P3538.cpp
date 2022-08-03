#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int b = 131;
const ull mod = 212370440130137957;
ull bb[500001], hh[500001];
int n, q;
char s[500001];
int sushu[500001], scnt;
bool vis[500001];

void checksushu() {
    for (int i = 2; i <= 500000; i++) {
        if (!vis[i]) {
            vis[i] = true;
            sushu[++scnt] = i;
        }
        for (int j = 1; i <= scnt && j * i <= 500000; j++) {
            vis[sushu[j] * i] = true;
            if (i % sushu[j] == 0) break;
        }
    }
}

inline ull Hash(int l, int r) { return hh[r] - bb[r - l + 1] * hh[l - 1]; }

bool check(int l, int r, int len) {
    ull ans1, ans2, cha = r - l - len;
    ans1 = ans2 = 0;
    // ans1 = (hh[r] - hh[l + len - 1] * bb[cha + 1] + mod) % mod;
    // ans2 = (hh[r - len] - hh[l - 1] * bb[cha + 1] + mod) % mod;
    ans1 = Hash(l + len, r);
    ans2 = Hash(l, r - len);
    // printf("l: %d, r: %d, len: %d, ans1: %llu, ans2: %llu\n", l, r, len, ans1,
    //        ans2);
    return ans1 == ans2;
}

int main() {
    bb[0] = 1;
    for (int i = 1; i < 500001; i++) bb[i] = bb[i - 1] * b % mod;
    cin >> n;
    scanf("%s", s + 1);
    hh[1] = s[1];
    for (int i = 2; i <= n; i++) {
        hh[i] = (hh[i - 1] * b + s[i]) % mod;
    }
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        for (int i = 1; i <= y - x + 1; i++) {
            if((y - x + 1) % i != 0) {
                continue;
            }
            // cout << "x: " << x << ", y: " << y << ", i: " << i << endl;
            if (check(x, y, i)) {
                cout << i << endl;
                break;
            }
            if(i == y - x + 1) {
                cout << y - x + 1 << endl;
            }
        }
    }
}