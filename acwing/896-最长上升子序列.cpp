// https://www.acwing.com/solution/content/23960/

#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int n, a[N], dp[N], q[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int len = 0;
    q[0] = INT_MIN;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (a[i] > q[mid])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }
    cout << len << endl;
}

/*
10
-5 -1 8 -4 3 -2 -5 -6 2 -6
*/