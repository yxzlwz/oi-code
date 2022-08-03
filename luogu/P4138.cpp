#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 2001;

int n, dp[N][N];
pii g[N];

bool cmp(const pii &a, const pii &b) { return a.first > b.first; }

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        g[i] = make_pair(a, b);
    }
    sort(g + 1, g + n + 1, cmp);

    memset(dp, -1, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (dp[i][j - 1 + g[i].first] != -1)
                dp[i][j - 1 + g[i].first] = max(dp[i][j - 1 + g[i].first],
                                                dp[i - 1][j - 1] + g[i].second);
            else
                dp[i][j - 1 + g[i].first] = dp[i - 1][j - 1 + g[i].first];
    }

    cout << *max_element(dp[n] + 1, dp[n] + n + 1) << endl;

    return 0;
}

/*
4
0 3
2 -2
1 -1
0 4
0 1

*/