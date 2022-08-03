#include <bits/stdc++.h>
using namespace std;

short res[5][5] = {{0, -1, 1, 1, -1},
                   {1, 0, -1, 1, -1},
                   {-1, 1, 0, -1, 1},
                   {-1, -1, 1, 0, 1},
                   {1, 1, -1, -1, 0}};

int a[201], b[201];

int main() {
    int n, al, bl, as = 0, bs = 0;
    cin >> n >> al >> bl;
    for (int i = 0; i < al; i++) cin >> a[i];
    for (int i = 0; i < bl; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        switch (res[a[i % al]][b[i % bl]]) {
            case 1:
                as++;
                break;
            case -1:
                bs++;
                break;
            default:
                break;
        }
    }
    cout << as << " " << bs;

    return 0;
}