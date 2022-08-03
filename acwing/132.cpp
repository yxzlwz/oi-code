#include <bits/stdc++.h>
using namespace std;

const int N = 2000001, M = 2001;

short people[N];

queue<int> group[M], q;
bool in_queue[M];

int main() {
    freopen("E:/Desktop/1.in", "r", stdin);
    for (int T = 1;; T++) {
        for (int i = 0; i < M; i++) {
            while (!group[i].empty()) group[i].pop();
            in_queue[i] = false;
        }
        memset(people, 0, sizeof(people));
        int n;
        cin >> n;
        if (!n) break;
        printf("Scenario #%d\n", T);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            for (int j = 0; j < x; j++) {
                int y;
                cin >> y;
                people[y] = i;
            }
        }
        string opt;
        int a;
        cin >> opt;
        while (opt != "STOP") {
            if (opt == "ENQUEUE") {
                cin >> a;
                group[people[a]].push(a);
                if (!in_queue[people[a]]) {
                    q.push(people[a]);
                    in_queue[people[a]] = true;
                }
            } else {
                int g = q.front();
                cout << group[g].front() << endl;
                group[g].pop();
                if (group[g].empty()) {
                    q.pop();
                    in_queue[g] = false;
                }
            }
            cin >> opt;
        }
    }
}
