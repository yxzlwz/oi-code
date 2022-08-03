#include <bits/stdc++.h >

using namespace std;

const int N = 1005;

struct part {  // 区间信息存于结构体中

    double l, r;

} a[N];

int x[N], y[N], n, d, ans;

bool cmp(part a, part b)  // 按区间右端点小到大排序

{
    return a.r < b.r;
}

inline void work()

{
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    for (int i = 1; i <= n; i++)

    {
        if (d < y[i])  // 不可能被侦查到

        {
            ans = -1;

            return;
        }

        a[i].l = x[i] - sqrt(1ll * d * d - 1ll * y[i] * y[i]);

        a[i].r = x[i] + sqrt(1ll * d * d - 1ll * y[i] * y[i]);
    }

    sort(a + 1, a + 1 + n, cmp);  // 排序

    ans = 1;

    double pos = a[1].r;

    for (int i = 2; i <= n; i++)

    {
        if (a[i].l <= pos && pos <= a[i].r)  // 情况1

            continue;

        else  // 情况2

            ans++, pos = a[i].r;
    }
}

int main()

{
    scanf("%d%d", &n, &d);

    if (n == d && d == 0) return 0;

    work();

    cout << ans;

    return 0;
}