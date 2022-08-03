#include <bits/stdc++.h>
using namespace std;

bool same_num(int a, int b) {
    bool num[10];
    memset(num, 0, sizeof(num));
    while (a) {
        if (num[a % 10]) return true;
        num[a % 10] = true;
        a /= 10;
    }
    while (b) {
        if (num[b % 10]) return true;
        num[b % 10] = true;
        b /= 10;
    }
    if (num[0]) return true;
    return false;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    bool flag = true;
    for (int i = 123; i <= 500; i++) {
        for (int j = i; j < 1000; j++) {
            if (same_num(i, j)) continue;
            for (int k = j; k < 1000; k++) {
                if (same_num(i, k) || same_num(j, k)) continue;
                if (j / float(i) == b / float(a) &&
                    k / float(j) == c / float(b) &&
                    k / float(i) == c / float(a)) {
                    cout << i << " " << j << " " << k << endl;
                    flag = false;
                }
            }
        }
    }
    if (flag) cout << "No!!!" << endl;
}