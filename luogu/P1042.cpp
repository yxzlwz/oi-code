#include <bits/stdc++.h>
using namespace std;
int main() {
    char a[62500], input;
    int len = 0;

    cin >> input;
    while (input != 'E') {
        a[len++] = input;
        cin >> input;
    }

    int w = 0, l = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == 'W')
            w++;
        else if (a[i] == 'L')
            l++;

        if ((w >= 11 || l >= 11) && (abs(w - l) >= 2)) {
            cout << w << ':' << l << endl;
            w = 0;
            l = 0;
        }
    }
    cout << w << ':' << l << endl;

    cout << endl;

    w = 0, l = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == 'W')
            w++;
        else if (a[i] == 'L')
            l++;

        if ((w >= 21 || l >= 21) && (abs(w - l) >= 2)) {
            cout << w << ':' << l << endl;
            w = 0;
            l = 0;
        }
    }
    cout << w << ':' << l << endl;
    cout << endl;

    return 0;
}