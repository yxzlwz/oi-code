#include <bits/stdc++.h>
using namespace std;

string months[12] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[31] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
int MIN = 9999;

int main()
{
    string _ = "-", s;
    cin >> s;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < days[i]; j++)
        {
            string t = months[i] + _ + day[j];
            int cnt = 0;
            for(int k = 0; k < 5; k++){
                if(s[k] != t[k])cnt++;
            }
            if(cnt < MIN) MIN = cnt;
        }
    }
    cout<<MIN;

    return 0;
}