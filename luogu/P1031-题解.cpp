#include <iostream>
using namespace std;
int main() {
    int a[101], n, tot = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    int ave = tot / n;
    for (int i = 0; i < n; i++) {
        a[i] = a[i] - ave;
    }
    // for (int i = 0; i < n; i++) cout << a[i] << " ";
    // cout << endl;
    for (int i = 0; i < n - 1; i++) {
        if (a[i]) {
            a[i + 1] += a[i];
            a[i] += -a[i];
            // cout << i << " " << i + 1 << "  ";
            // for (int i = 0; i < n; i++) cout << a[i] << " ";
            // cout << endl;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}