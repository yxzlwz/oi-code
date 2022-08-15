
#include <bits/stdc++.h>
using namespace std;

const int N = 12, M = 1 << N;

long long f[N][M];

bool st[M];

vector<int> state[M];  //二维数组记录合法的状态
// vector<vector<int>> state(M);  //两种写法等价:二维数组

int m, n;

int main() {
    while (cin >> n >> m,
           n || m) {  //读入n和m，并且不是两个0即合法输入就继续读入

        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0;

            bool isValid = true;

            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    if (cnt & 1) {
                        isValid = false;
                        break;
                    }

                    cnt = 0;
                } else
                    cnt++;
            }
            if (cnt & 1) isValid = false;

            st[i] = isValid;
        }

        for (int j = 0; j < (1 << n); j++) {
            state[j].clear();

            for (int k = 0; k < (1 << n); k++) {
                if ((j & k) == 0 && st[j | k]) state[j].push_back(k);
            }
        }

        memset(f, 0, sizeof f);

        f[0][0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < (1 << n); j++) {
                for (auto k : state[j]) f[i][j] += f[i - 1][k];
            }
        }

        cout << f[m][0] << endl;
    }
}