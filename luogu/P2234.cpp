#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    set<ll> s;
    ll a;
    cin >> a;
    s.insert(a);
    ll ans = a;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        auto p = s.lower_bound(a);
        if (p == s.end()) {
            p--;
            ans += abs(a - *p);
            s.insert(a);
            continue;
        } else if (p == s.begin()) {
            ans += abs(a - *p);
            s.insert(a);
            continue;
        }
        auto p1 = p--;
        ans += min(abs(*p - a), abs(*(p1)-a));
        s.insert(a);
    }
    cout << ans << endl;
}