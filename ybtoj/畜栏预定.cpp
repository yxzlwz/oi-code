#include <bits/stdc++.h>
using namespace std;

int n, g[100000], lg;

struct cow {
    int a, b, id, grass;
} m[100000];

bool ccmp1(cow x, cow y) { return x.a < y.a; }
bool ccmp2(cow x, cow y) { return x.id < y.id; }

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m[i].a >> m[i].b;
        m[i].id = i;
    }

    sort(m + 1, m + n + 1, ccmp1);

    lg = 1;
    g[lg] = m[1].b;
    m[1].grass = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= lg; j++) {
            if (g[j] < m[i].a) {
                g[j] = m[i].b;
                m[i].grass = j;
                break;
            }
            if (j == lg) {
                lg++;
                g[lg] = m[i].b;
                m[i].grass = lg;
                break;
            }
        }
    }

    cout << lg << endl;
    sort(m + 1, m + n + 1, ccmp2);
    for (int i = 1; i <= n; i++) {
        cout << m[i].grass << endl;
    }
}