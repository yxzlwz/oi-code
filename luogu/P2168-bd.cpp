#include <bits/stdc++.h>
using namespace std;

const int N = 10001;
int n, k, cnt;
long long ans = 0ll, w[N];

struct node {
    int v, h;
};

inline bool operator<(const node &a, const node &b) {
    if (a.v != b.v)
        return a.v > b.v;
    else
        return a.h > b.h;
}

priority_queue<node> q;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        node tmp;
        tmp.v = (long long)w[i];
        tmp.h = 0;
        q.push(tmp);
    }
    cnt = n;
    if ((n - 1) % (k - 1) != 0) cnt += k - 1 - (n - 1) % (k - 1);
    for (int i = 1; i <= cnt - n; i++) {
        node tmp;
        tmp.v = 0ll;
        tmp.h = 0;
        q.push(tmp);
    }
    while (cnt != 1) {
        long long val = 0ll;
        int deep = 0;
        for (int i = 1; i <= k; i++) {
            node tot = q.top();
            val += (long long)tot.v;
            deep = max(deep, tot.h);
            q.pop();
        }
        cnt -= k - 1;
        ans += val;
        node tmp;
        tmp.v = val;
        tmp.h = deep + 1;
        q.push(tmp);
    }
    cout << ans << endl << q.top().h << endl;
    return 0;
}