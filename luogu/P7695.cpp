#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 2;
    while (n--)
    {
        i = i * 2 - 1;
    }
    cout << i * i;
}