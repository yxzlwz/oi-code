#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 5001;

int n, dp[N];
pii a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j].second > a[i].second && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << *max_element(dp + 1, dp + n + 1) << endl;
    return 0;
}
