#include <iostream>
using namespace std;
int main()
{
    string a;
    int maxn = 0, minn = 999999;
    cin >> a;
    for (int i = 0; i < 26; i++)
    {
        int cnt = 0;
        char t = 'a' + i; // 遍历每个字母
        for (int j = 0; j < a.length(); j++)
        {
            if (a[j] == t)
                cnt++;
        }
        if (cnt && cnt > maxn)
            maxn = cnt;
        if (cnt && cnt < minn)
            minn = cnt;
    }
    int c = maxn - minn;
    // cout << c << " " << maxn << " " << minn << endl;
    if (c == 1 || (c != 2 && c % 2 == 0)) // 非2的偶数一定是质数
    {
        cout << "No Answer\n0";
        return 0;
    }
    for (int i = 3; i <= c / 2 + 1; i += 2) // 判断是否是质数
    {
        if (c % i == 0)
        {
            cout << "No Answer\n0";
            return 0;
        }
    }
    cout << "Lucky Word\n"
         << c;

    return 0;
}