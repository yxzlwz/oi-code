#include <bits/stdc++.h>
using namespace std;
#define int long long

const int Q = 100001;

const int rl_400 = 146100, rl_4 = 1461, glg_400 = 146097;
const int bce = rl_400 * 1178 + 365;
const int P_DAYS[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
          R_DAYS[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n, q[Q];
// int year = -4713, day = 1, cnt;
int year = 1580, day = 365, cnt;

void add_year() {
    int od = day;
    if (year < -1)
        cnt += year % 4 ? 365 : 366;
    else if (year == -1)
        cnt += 365, year++;
    else if (0 < year && year < 1581 || year == 1581 && day <= 277)
        cnt += year % 4 ? 365 : 366;
    else if (year == 1582)
        cnt += 355;
    else
        cnt +=
            (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 365 : 366;

    year++;
}

void add_day() {
    int ds;
    if (year == 1582)
        ds = 355;
    else if (year < 1582)
        ds = year % 4 ? 365 : 366;
    else if (year > 1582)
        ds =
            (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 366 : 365;

    day++, cnt++;
    if (day == ds + 1) {
        day = 1;
        year++;
    }
    if (year == 0) year++;
    return;
}

// int doy(int y) {
//     if (y < 1581) {
//         return year % 4 != 0 ? 366 : 365;
//     }else if(y == )
// }

signed main() {
    // cin >> n;
    // for (int i = 1; i <= n; i++) cin >> q[i];
    // sort(q + 1, q + n + 1);

    // for (int i = 1; i <= n; i++) {
    //     while (q[i] - cnt > rl_400 && cnt + rl_400 < bce)
    //         cnt += rl_400, year += 400;
    //     while (q[i] - cnt > rl_4 && cnt + rl_4 < bce) cnt += rl_4, year += 4;
    //     // while()
    // }
    for (int i = 1; i <= 4; i++) {
        add_year();
        cout << year << " " << day << " " << cnt << endl;
    }
    cout << endl;
    for (int i = 1; i <= 4; i++) {
        add_day();
        cout << year << " " << day << " " << cnt << endl;
    }

    return 0;
}