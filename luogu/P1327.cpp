#include <bits/stdc++.h>
using namespace std;

int a[10001];

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                cnt++;
                swap(a[j], a[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl << cnt;

    return 0;
}