#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main() {
    int n, a, b, t;
    cin >> n >> a >> b;
    while (n--) {
        cin >> t;
        pq.push(t);
    }

    int l = 0;
    while (true) {
        l += a;
        t = pq.top();
        pq.pop();
        pq.push(t - b);
        if (pq.top() <= l) break;
    }

    cout << l / a;

    return 0;
}