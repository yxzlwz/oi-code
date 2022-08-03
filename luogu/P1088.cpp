#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    while (m--) next_permutation(a.begin(), a.end());
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}