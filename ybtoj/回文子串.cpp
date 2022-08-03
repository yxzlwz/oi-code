#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int k = 131;

ull hash1[1000005], hash2[1000005], jz[1000005];

int main() {
    jz[0] = 1;
    for (int i = 1; i <= 1000003; i++) {
        jz[i] = jz[i - 1] * k;
    }
    string s;
    cin >> s;
    for (int i = 1; s != "END"; i++) {
        int len = s.length();
        hash1[0] = s[0];
        hash2[len - 1] = s[len - 1];
        for (int j = 1; j < len; j++) {
            hash1[j] = hash1[j - 1] * k + s[j];
            hash2[len - j] = hash2[len - j + 1] * k + s[len - j];
        }
        int ans = 0;
        for (int j = 0; j < len; j++) {
            int maxx = min(j, len - j - 1);
            // cout << "j = " << j << " maxx = " << maxx << endl;
            for (int l = 1; l <= maxx; l++) {
                // cout << j << " " << l << " " << hash1[j] - hash1[j - l] *
                // jz[l]
                //      << " " << hash2[j] - hash2[j + l] * jz[l] << endl;
                if (hash1[j] - hash1[j - l] * jz[l] !=
                    hash2[j] - hash2[j + l] * jz[l])
                    break;
                ans = max(ans, l * 2 + 1);
            }
            for (int l = 1; l <= maxx; l++) {
                // cout << j << " " << l << " " << hash1[j] - hash1[j - l] *
                // jz[l]
                //      << " " << hash2[j + 1] - hash2[j + l + 1] * jz[l] <<
                //      endl;
                if (hash1[j] - hash1[j - l] * jz[l] !=
                    hash2[j + 1] - hash2[j + l + 1] * jz[l])
                    break;
                ans = max(ans, l * 2);
            }
        }
        // cout << "====================ans=" << ans << endl;
        cout << "Case " << i << ": " << ans << endl;
        cin >> s;
    }
}