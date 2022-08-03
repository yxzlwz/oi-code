#include <bits/stdc++.h>
using namespace std;

int a[1000];
int dp[1000];

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    
    int l, s, t, m, temp;
    cin >> l >> s >> t >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        a[i] = temp;
    }

    for (int i = 1; i <= l; i++)
    {
        int stone = 0;
        for (int k = 0; k < m; k++)
            if (a[k] == i)
            {
                stone = 1;
                break;
            }
        for (int j = s; j <= t; j++)
        {
            if (i < j)
                break;
            if(dp[(i - j) % 900] == -1)continue;

            if(dp[i % 900] == -1)dp[i % 900] = dp[(i - j) % 900] + stone;
            else dp[i % 900] = min(dp[i % 900], dp[(i - j) % 900] + stone);
        }
    }

    // for (int i = 1; i <= l; i++)
        // printf("%d:%d ", i, dp[i]);

    cout << dp[l] << endl;

    return 0;
}