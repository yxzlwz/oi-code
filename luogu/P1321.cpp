#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int boy = 0, girl = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'b' or s[i + 1] == 'o' or s[i + 2] == 'y')
            boy++;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'g' or s[i + 1] == 'i' or s[i + 2] == 'r' or s[i + 3] == 'l')
            girl++;

    cout << boy << endl
         << girl;

    return 0;
}