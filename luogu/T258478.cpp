#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        map<char, int> m;
        bool ok = 0;
        for (auto c : s) {
            m[c]++;
            if (m[c] >= 4) {
                ok = 1;
                break;
            }
        }
        if (ok || (m['X'] && m['D'])) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
