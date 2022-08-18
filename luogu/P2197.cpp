#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = 0;
        while (n--) {
            int a;
            cin >> a;
            ans ^= a;
        }
        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}