#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

int n, a[N];

inline int lowbit(int i) { return i & (-i); }



int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}