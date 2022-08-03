#include <bits/stdc++.h>
using namespace std;

stack<int> s1, s2, s1qzh;
int f[1000001], fc;

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        char c;
        cin >> c;
        int a;
        if (c == 'I') {
            cin >> a;
            s1.push(a);
            if (s1qzh.empty()) {
                s1qzh.push(a);
                f[++fc] = a;
            } else {
                s1qzh.push(s1qzh.top() + a);
                fc++;
                f[fc] = max(f[fc - 1], s1qzh.top());
            }
        } else if (c == 'D') {
            if (!s1.empty()) {
                s1.pop();
                s1qzh.pop();
                fc--;
            }
        } else if (c == 'L') {
            if (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
                s1qzh.pop();
                fc--;
            }
        } else if (c == 'R') {
            if (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
                if (s1qzh.empty()) {
                    s1qzh.push(s1.top());
                    f[++fc] = a;
                } else {
                    s1qzh.push(s1qzh.top() + s1.top());
                    fc++;
                    f[fc] = max(f[fc - 1], s1qzh.top());
                }
            }
        } else if (c == 'Q') {
            cin >> a;
            cout << f[a] << endl;
        }
    }
}
