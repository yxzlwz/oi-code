#include <iostream>
using namespace std;

struct node
{
    string name;
    int qm, bj;
    char gb, xb;
    int lw, jxj = 0;
} a[1001];

int main()
{
    int n;
    cin >> n;
    int MAX = 0, SUM = 0;
    for (int i = 1; i <= n; i++)
    {
        node t;
        cin >> t.name >> t.qm >> t.bj >> t.gb >> t.xb >> t.lw;
        if (t.qm > 80 && t.lw)
            t.jxj += 8000;
        if (t.qm > 85 && t.bj > 80)
            t.jxj += 4000;
        if (t.qm > 90)
            t.jxj += 2000;
        if (t.qm > 85 && t.xb == 'Y')
            t.jxj += 1000;
        if (t.bj > 80 && t.gb == 'Y')
            t.jxj += 850;
        a[i] = t;
        if (t.jxj > a[MAX].jxj)
            MAX = i;
        SUM += t.jxj;
    }
    cout << a[MAX].name << endl
         << a[MAX].jxj << endl
         << SUM;
}