#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int n, k;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        q.push(i);
    while (q.size() > 1)
    {
        for (int i = 1; i < k; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << " ";
        q.pop();
    }
    cout << q.front();
    return 0;
}