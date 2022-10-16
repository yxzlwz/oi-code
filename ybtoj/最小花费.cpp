#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> pii;

const int N = 2001;

bool computed[N];
int c[N][N];
vector<pii> node[N];

struct EDGE {
    int u, v, w;
} edge[N * N];

bool cmp(const EDGE &x, const EDGE &y) { return x.w < y.w; }

signed main() {
    int n;
    cin >> n;
    memset(c, -1, sizeof(c));
    int ccnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // for (int j = n; j >= i; --j) {
            cin >> c[i][j];
            edge[++ccnt].u = i;
            edge[ccnt].v = j;
            edge[ccnt].w = c[i][j];
        }
        edge[++ccnt].u = i;
        edge[ccnt].v = i;
        cin >> edge[ccnt].w;
    }

    sort(edge + 1, edge + ccnt + 1, cmp);

    int ans = 0, cnt = 0;

    for (int i = 1; i <= ccnt && cnt < n; i++) {
        const EDGE d = edge[i];
        // cout << ccnt << " " << i << " " << cnt << endl;
        // cout << "-- " << d.u << " " << d.v << endl;
        if (computed[d.u] && computed[d.v])
            continue;
        else if (computed[d.u] || computed[d.v] || d.u == d.v) {
            ans += d.w;
            const int cur = computed[d.u] ? d.v : d.u;
            computed[cur] = true, cnt++;
            const int size = node[cur].size();
            for (int j = 0; j < size; j++) {
                const int v = node[cur][j].first, w = node[cur][j].second;
                if (computed[v]) continue;
                computed[v] = true, cnt++;
                ans += w;
            }
            node[cur].clear();
            // puts("08976");
            continue;
        }
        // puts("====");
        node[d.u].push_back(make_pair(d.v, d.w));
        node[d.v].push_back(make_pair(d.u, d.w));
    }

    cout << ans << endl;

    return 0;
}
