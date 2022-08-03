#include <iostream>
using namespace std;

int c[1001];

struct note
{
    int x, step;
} que[2500001];

int main()
{
    int n, m[1001], a, b;
    cin >> n >> a >> b;
    if(a == b){
        cout<<0;
        return 0;
    }
    for(int i = 1; i <= n; i++)cin>>m[i];

    int head = 1, tail = 1;
    que[tail].x = a;
    que[tail].step = 0;
    tail++;
    int x;
    while (head < tail)
    {
        for (int i = 0; i <= 1; i++)
        {
            if(i == 0 && que[head].x + m[que[head].x] <= n)
                x = que[head].x + m[que[head].x];
            else if(que[head].x - m[que[head].x] > 0)
                x = que[head].x - m[que[head].x];
            else continue;
            if (x == b)
            {
                cout << que[head].step + 1 << endl;
                return 0;
            }
            if(!c[x]){
            c[x] = 1;
            que[tail].x = x;
            que[tail].step = que[head].step + 1;
            tail++;}
        }
        head++;
    }
    cout<<-1;
    return 0;
}