#include <bits/stdc++.h>
using namespace std;
int n, a[3000001];
typedef pair<int, int> pii;
int main() {
    cin >> n;
    stack<pii> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i; i--) {
        while (!s.empty() && s.top().first <= a[i]) s.pop();
        pii temp = make_pair(a[i], i);
        if (s.empty())
            a[i] = 0;
        else
            a[i] = s.top().second;
        s.push(temp);
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}