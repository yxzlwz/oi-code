#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> xgd;
priority_queue<int, vector<int>, less<int>> dgd;

int main() {
    int T;
    cin >> T;
    while (T--) {
        while (!xgd.empty()) xgd.pop();
        while (!dgd.empty()) dgd.pop();
        int no, n;
        cin >> no >> n;
        cout << no << " " << (n + 1) / 2 << endl;
        int a;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            dgd.push(a);
            if (!dgd.empty() && !xgd.empty())
                cout << ';' << i << ' ' << dgd.top() << ' ' << xgd.top()
                     << endl;
            while (!dgd.empty() && !xgd.empty() && dgd.top() > xgd.top()) {
                xgd.push(dgd.top());
                dgd.pop();
            }
            while (!dgd.empty() && !xgd.empty() && dgd.size() <= xgd.size()) {
                dgd.push(xgd.top());
                xgd.pop();
            }
            while (!dgd.empty() && !xgd.empty() &&
                   xgd.size() - dgd.size() > 1) {
                dgd.push(xgd.top());
                xgd.pop();
            }
            if (i % 2) {
                if (!dgd.empty())
                    cout << dgd.top() << " ";
                else
                    cout << "MO";
            }
        }
        cout << endl;
    }
}
