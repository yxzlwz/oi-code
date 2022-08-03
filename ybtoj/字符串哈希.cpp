#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int jz = 131;

set<int> s;

ull k[1600];

ull str_hash(string s) {
    ull ans = 0;
    for (int i = 0; i < s.length(); i++) ans = ans * jz + s[i];
    return ans;
}

int main() {
    // k[0] = 1;
    // for (int i = 1; i <= 1500; i++) {
    //     k[i] = k[i - 1] * jz;
    // }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        s.insert(str_hash(x));
    }
    cout << s.size() << endl;
}
