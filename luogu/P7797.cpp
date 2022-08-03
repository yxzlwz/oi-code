#include <bits/stdc++.h>
using namespace std;

struct node {
    int t, u;
};

int main() {
    map<char, node> a;
    node t;
    t.t = 11;
    t.u = 11;
    a['A'] = t;
    t.t = t.u = 4;
    a['K'] = t;
    t.t = t.u = 3;
    a['Q'] = t;
    t.t = 20;
    t.u = 2;
    a['J'] = t;
    t.t = t.u = 10;
    a['T'] = t;
    t.t = 14;
    t.u = 0;
    a['9'] = t;
    t.t = t.u = 0;
    a['8'] = a['7'] = t;

    int n, s = 0;
    char b;
    cin >> n >> b;

    for (int i = 0; i < 4 * n; i++) {
        char x, y;
        cin >> x >> y;
        if (b == y)
            s += a[x].t;
        else
            s += a[x].u;
    }
    cout << s;
}