#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        ll d = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

int main() {
    ll a, b, m, n, l;
    cin >> a >> b >> m >> n >> l;

    ll x, y;
    ll d = exgcd(m - n, l, x, y);

    if ((b - a) % d)
        puts("Impossible");
    else {
        x *= (b - a) / d;
        ll t = abs(l / d);
        cout << (x % t + t) % t << endl;  // 为什么不行：cout << x % t << endl;？
    }

    return 0;
}