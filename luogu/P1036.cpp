#include <iostream>
using namespace std;

int n, k, x[100], cnt, lock[100], t, len, had[100000];

int qjc(int a){
    int ans = 1;
    while(a){
        ans *= a;
        a--;
    }
    return ans;
}

void dfs(int step, int p)
{
    if (step == k + 1)
    {
        for (int i = 0; i < len; i++)
        {
            if (had[i] == t)
            {
                cnt++;
                return;
            }
        }
        int middle = t / 2 + 1;
        if (t != 2 && middle % 2 == 0)
            return;
        for (int i = 3; i < middle; i += 2)
        {
            if (t % i == 0)
            {
                // cout << t << " " << i << endl;
                return;
            }
        }
        had[len++] = t;
        cnt++;
        return;
    }

    for (int i = p; i < n; i++)
    {
        if (!lock[i])
        {
            lock[i] = 1;
            t += x[i];
            dfs(step + 1, i);
            t -= x[i];
            lock[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    dfs(1, 0);

    cout << cnt;
    return 0;
}