#include <bits/stdc++.h>
using namespace std;

const double sqrt5 = sqrt(5);

int main() {
    int n;
    cin >> n;
    cout << fixed << setprecision(2)
         << (pow((1 + sqrt5) / 2.0, n) - pow((1 - sqrt5) / 2.0, n)) / sqrt5;
}