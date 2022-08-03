#include <iostream>
using namespace std;
int t[1001];
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        t[s[i]]++;
    }
    int m = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (t[i] > m)
            m = t[i];
    }
    cout << m;
    return 0;
}