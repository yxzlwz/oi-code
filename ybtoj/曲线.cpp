#include <bits/stdc++.h>
using namespace std;
struct hs {
    double a, b, c;
} h[10011];
int n;
double js(hs hh, double x) { return hh.a * x * x + hh.b * x + hh.c; }
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> h[i].a >> h[i].b >> h[i].c;
        double l = 0, lmid, rmid, r = 1000;
        while (r - l > 1e-11) {
            lmid = l + (r - l) / 3.0;
            rmid = r - (r - l) / 3.0;
            double lmax = -0x3f3f3f3f, rmax = -0x3f3f3f3f;
            for (int i = 1; i <= n; i++) {
                lmax = max(lmax, js(h[i], lmid));
                rmax = max(rmax, js(h[i], rmid));
            }
            if (lmax > rmax)
                l = lmid;
            else
                r = rmid;
        }
        double maxx = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++) maxx = max(maxx, js(h[i], r));
        printf("%.4lf\n", maxx);
    }
    return 0;
}