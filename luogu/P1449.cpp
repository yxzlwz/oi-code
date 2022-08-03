#include <bits/stdc++.h>
using namespace std;

stack<int> a;

int main() {
    string s;
    cin >> s;
    int temp = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            temp = temp * 10 + (s[i] - '0');
        } else if (s[i] == '.') {
            a.push(temp);
            temp = 0;
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int y = a.top();
            a.pop();
            int x = a.top();
            a.pop();
            int z;
            switch (s[i]) {
                case '+':
                    z = x + y;
                    break;
                case '-':
                    z = x - y;
                    break;
                case '*':
                    z = x * y;
                    break;
                case '/':
                    z = x / y;
                    break;
            }
            a.push(z);
        } else if (s[i] == '@')
            cout << a.top() << endl;
    }

    return 0;
}
