#include <bits/stdc++.h>
using namespace std;
stack<int> a;
int main()
{
    string s;
    cin >> s;
    for (int i = 0; s[i] != '@'; i++)
    {
        if (s[i] == '(')
            a.push(i);
        else if (s[i] == ')')
        {
            if (!a.empty())
                a.pop();
            else
            {
                cout << "NO";
                return 0;
            }
        }
    }
    if (a.empty())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}