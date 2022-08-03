#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 32;
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] >= 'A' && b[i] <= 'Z')
            b[i] += 32;
    }
    int l = 1, p[100000001];
    p[0] = -1;
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] == ' ')
            p[l++] = i;
    }
    bool had = 0;
    int time = 0, head;
    for (int i = 0; i < l; i++)
    {
        if (p[i + 1] - p[i] - 1 != a.length())
            continue;
        bool is = 1;
        for (int j = p[i] + 1, k = 0; j < p[i + 1]; j++, k++)
        {
            if (b[j] != a[k])
            {
                is = 0;
                break;
            }
        }
        if (is)
        {
            if (!had)
            {
                had = 1;
                head = p[i] + 1;
            }
            time++;
        }
    }
    if (had)
    {
        cout << time << " " << head;
    }
    else
        cout << -1;
    return 0;
}