#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500001;

typedef pair<int, int> pii;

struct NODE {
    bool left;
    int fa;
    vector<int> son;
} node[N];

int n, ans[N], q[N];

stack<int> st, stt;
void dfs(int x) {
    int t = 0, tt = 0;
    if (node[x].left) {
        st.push(x);
        tt = 1;
        ans[x] = 0;
    } else if (st.empty()) {
        ans[x] = 0;
    } else {
        ans[x] = 1 + ans[st.top() - 1];
        t = st.top();
        st.pop();
    }
    q[x] = ans[x] + q[node[x].fa];
    for (int i = 0; i < node[x].son.size(); i++) {
        dfs(node[x].son[i]);
    }
    if (t) st.push(t);
    if (tt) st.pop();

    return;
}

signed main() {
    freopen("/mnt/d/Desktop/brackets8.in", "r", stdin);
    // freopen("brackets.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        char t;
        cin >> t;
        node[i].left = t == '(';
    }
    node[1].fa = 0;
    for (int i = 2; i <= n; i++) {
        int t;
        cin >> t;
        node[i].fa = t;
        node[t].son.push_back(i);
    }
    dfs(1);
    int res = 0;
    // for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    // cout << "\n";
    // for (int i = 1; i <= n; i++) cout << q[i] << " ";
    // cout << "\n";
    for (int i = 1; i <= n; i++) res ^= q[i] * i;

    cout << res << endl;
}