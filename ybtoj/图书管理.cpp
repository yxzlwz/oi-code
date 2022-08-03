#include <bits/stdc++.h>
using namespace std;
map<string, bool> mp;
int main() {
    string s1;
    char s2[1000001];
    int n;
    cin >> n;
    while (n--) {
        cin >> s1;
        cin.getline(s2, 1000001);
        if (s1 == "add")
            mp[s2] = true;
        else if (s1 == "find")
            if (mp.find(s2) != mp.end())
                cout << "yes" << endl;
            else
                cout << "no" << endl;
    }
}