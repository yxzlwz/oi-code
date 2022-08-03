#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    map<string, int> a;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        a[s] = 1;
    }
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        if (a[s] == 1) {
            cout << "OK\n";
            a[s]++;
        } else if (a[s] >= 2)
            cout << "REPEAT\n";
        else
            cout << "WRONG\n";
    }
}