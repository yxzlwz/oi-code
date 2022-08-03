#include <iostream>
using namespace std;
int main() {
    int n, l, r;
    cin >> n >> l >> r;
    int k = l / n, c = l;
    while (c < n * (k + 1) && c <= r) c++;
    cout << c - n * k - 1;

    return 0;
}