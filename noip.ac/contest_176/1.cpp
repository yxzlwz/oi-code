#include <iostream>
using namespace std;
int main() {
    int a[4];
    for (int i = 1; i <= 3; ++i) cin >> a[i];
    // 根据需要进行排序操作：sort(a + 1, a + 3 + 1)
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            for (int k = 1; k <= 3; ++k) {
                if (i != j && i != k && j != k) {
                    cout << a[i] << a[j] << a[k] << endl;
                }
            }
        }
    }
}