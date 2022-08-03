#include <bits/stdc++.h>
using namespace std;

int n, len;
char c[501];

void move(int m) {}

void mv() {}

int main() {
    cin >> n;
    len = n * 2 + 2;
    for (int i = 1; i <= n; i++) c[i] = 'o';
    for (int i = n + 1; i <= n * 2; i++) c[i] = '*';
    c[n * 2 + 1] = c[n * 2 + 2] = '--';
    move(n);
}
