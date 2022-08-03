#include <bits/stdc++.h>
using namespace std;

const int N = 5001, R = 1000001;

int n, r, ecnt;
int head[N], w[R], nxt[R], to[R];
int d1[N], d2[N];

struct node {
    int from, to, w;
    friend bool operator<(const node &a, const node &b) { return a.w > b.w; }
};

priority_queue<node> q;

inline void add_edge(int from, int v, int val) {
    nxt[++ecnt] = head[from];
    head[from] = ecnt;
    to[ecnt] = v;
    w[ecnt] = val;
    nxt[++ecnt] = head[v];
    head[v] = ecnt;
    to[ecnt] = from;
    w[ecnt] = val;
}

int main() {
    cin >> n >> r;
    for (int i = 1; i <= r; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        add_edge(from, to, w);
    }
    memset(d1, 0x3f, sizeof(d1));
    memset(d2, 0x3f, sizeof(d2));
    node t;
    t.to = 1;
    t.w = 0;
    q.push(t);
    d1[1] = 0;
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        for (int i = head[t.to]; i; i = nxt[i]) {
            node u;
            u.to = to[i];
            u.w = w[i];
            if (d1[to[i]] > d1[t.to] + w[i]) {
                d2[to[i]] = d1[to[i]];
                d1[to[i]] = d1[t.to] + w[i];
                q.push(u);
            } else if (d2[to[i]] > d1[t.to] + w[i] &&
                       d1[to[i]] != d1[t.to] + w[i]) {
                d2[to[i]] = d1[t.to] + w[i];
                q.push(u);
            } else if (d2[to[i]] > d2[t.to] + w[i]) {
                d2[to[i]] = d2[t.to] + w[i];
                q.push(u);
            }
        }
    }
    cout << d2[n] << endl;
    return 0;
}