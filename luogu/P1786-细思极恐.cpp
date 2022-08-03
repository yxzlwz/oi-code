/*输入数据
9
DrangonflyKang BangZhu 100000 66
RenZaiJiangHu FuBangZhu 80000 60
absi2011 FuBangZhu 90000 60
BingQiLingDeYanLei HuFa 89000 58
Lcey HuFa 30000 49
BangYou3 ZhangLao 1000 1
BangYou1 TangZhu 100 40
BangYou2 JingYing 40000 10
BangYou4 BangZhong 400 1
*/


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
    // freopen("D:/Desktop/11.txt", "r", stdin);
    // freopen("D:/Desktop/1.txt", "w", stdout);

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

    // cout << endl;
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) cout << a[i].id << " ";
    cout << endl << n << endl;
    long long l = 0, i;
    for (i = 0; i < 3; i++) {
        cout << i << " ";
        if (n - l >= zw[i].cnt) {
            cout << i << " ";
            sort(a + l, a + l + zw[i].cnt, cmpp);
            cout << i << "\n";
            printf("%ld   ", i);
            printf("i:%ld  %ld %ld  i:%ld cnt:%ld\n", i, l, (l + zw[i].cnt), i,
                   zw[i].cnt);
            // for (long long j = l; j < l + zw[i].cnt; j++)
            //     cout << a[j].id << " " << a[j].name << " " << zw[i].name << "
            //     "
            //          << a[j].dj << endl;
            // printf("%ld %ld  i:%ld cnt:%ld\n", l, (l + zw[i].cnt), i,
            //        zw[i].cnt);

            l += zw[i].cnt;
        } else
            break;
    }
    // if (n - l > 0) {
    //     sort(a + l, a + n, cmpp);
    //     for (long long j = l; j < n; j++)
    //         cout << a[j].id << " " << a[j].name << " " << zw[i].name << " "
    //              << a[j].dj << endl;
    // }

    return 0;
}