#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int i = 0;
    while(i < n){
        int k = 1;
        while(a[i + 1] == a[i])i++,k++;
        cout<<a[i]<<" "<<k<<endl;
        i++;
    }
    return 0;
}