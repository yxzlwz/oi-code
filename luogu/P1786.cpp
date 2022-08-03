#include <bits/stdc++.h>
using namespace std;

struct node {
    string name, zw;
    long long bg, dj, id;
} a[200], fbz[2];

struct Node {
    string name;
    long long cnt;
} zw[10];

long long fbzl = 0;

bool cmp(node x, node y) {
    if (x.bg != y.bg)
        return x.bg > y.bg;
    else
        return x.id < y.id;
}

bool cmpp(node x, node y) {
    if (x.dj != y.dj)
        return x.dj > y.dj;
    else
        return x.id < y.id;
}

int main() {
    zw[0].name = "HuFa";
    zw[0].cnt = 2;
    zw[1].name = "ZhangLao";
    zw[1].cnt = 4;
    zw[2].name = "TangZhu";
    zw[2].cnt = 7;
    zw[3].name = "JingYing";
    zw[3].cnt = 25;
    zw[4].name = "BangZhong";
    zw[4].cnt = 100000000;

    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].zw >> a[i].bg >> a[i].dj;
        a[i].id = i;
        if (a[i].zw == "BangZhu") {
            cout << a[i].name << " " << a[i].zw << " " << a[i].dj << endl;
            i--;
            n--;
        } else if (a[i].zw == "FuBangZhu") {
            fbz[fbzl++] = a[i];
            i--;
            n--;
        }
    }
    if (fbz[0].dj < fbz[1].dj) swap(fbz[0], fbz[1]);
    for (int i = 0; i < 2; i++)
        cout << fbz[i].name << " " << fbz[i].zw << " " << fbz[i].dj << endl;

    sort(a, a + n, cmp);
    long long l = 0, i;
    for (i = 0; i < 4; i++) {
        if (n - l >= zw[i].cnt) {
            // cout << i << zw[i].name << zw[i].cnt << endl;
            sort(a + l, a + l + zw[i].cnt, cmpp);
            for (long long j = l; j < l + zw[i].cnt; j++)
                cout << a[j].name << " " << zw[i].name << " " << a[j].dj
                     << endl;
            l += zw[i].cnt;
        } else
            break;
    }
    if (n - l > 0) {
        sort(a + l, a + n, cmpp);
        for (long long j = l; j < n; j++)
            cout << a[j].name << " " << zw[i].name << " " << a[j].dj << endl;
    }

    return 0;
}