#include <bits/stdc++.h>
using namespace std;

char z[1001], x[1001], y[1001];
int n;

void huiwen() {
    for (int i = 0; i < strlen(x); i++) {
        y[i] = x[strlen(x) - i - 1];
    }
    y[strlen(x)] = '\0';
}

bool same() {
    if (strlen(x) != strlen(y)) return 0;
    for (int i = 0; i < strlen(x); i++) {
        if (x[i] != y[i]) return 0;
    }
    return 1;
}

void gjj() {
    memset(z, '\0', sizeof(z));
    int jw = 0, i;
    if (strlen(x) < strlen(y)) {
        x[strlen(y)] = '\0';
        int lenx = strlen(x);
        for (int i = strlen(x) - 1; i >= 0; i++) {
            swap(x[i], x[strlen(y) - lenx + i]);
        }
        for (int i = 0; i < strlen(y) - lenx; i++) x[i] = '0';
    } else if (strlen(x) > strlen(y)) {
        y[strlen(x)] = '\0';
        int leny = strlen(y);
        for (int i = strlen(y) - 1; i >= 0; i++) {
            swap(y[i], y[strlen(x) - leny + i]);
        }
        for (int i = 0; i < strlen(x) - leny; i++) y[i] = '0';
    }
    for (i = 1; i <= strlen(x) && i <= strlen(y); i++) {
        z[i - 1] = (x[strlen(x) - i] - '0') + (y[strlen(y) - i] - '0') + jw;
        jw = z[i - 1] / n;
        if (jw > 0) z[i - 1] %= n;
        z[i - 1] %= n;
        z[i - 1] += '0';
    }
    if (jw) {
        z[i - 1] = jw + '0';
    }
    for (int i = 0; i < strlen(z); i++) swap(z[i], z[strlen(z) - i - 1]);
}

void z_to_x() {
    for (int i = 0; i < strlen(z); i++) {
        x[i] = z[i];
    }
    x[strlen(z)] = '\0';
}

int main() {
    freopen("E:/Desktop/P1015_1.in", "r", stdin);
    // freopen("E:/Desktop/P1015_1.out", "w", stdout);
    cin >> n;
    cin.getline(x, sizeof(x));
    cin.getline(x, sizeof(x));
    huiwen();
    int step = 1;
    while (!same() && step <= 30) {
        gjj();
        z_to_x();
        huiwen();
        step++;
    }

    if (same())
        cout << "STEP=" << step - 1 << endl;
    else
        cout << "Impossible!" << endl;

    return 0;
}