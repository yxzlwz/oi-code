#include<bits/stdc++.h>
using namespace std;

int f[10000];

int main(){
    for(int i = 101; i <= 111; i++)
        f[i] = i - 10;
    for(int i = 100; i >= 1; i--)
        f[i] = f[f[i + 11]];
    int x;
    while(scanf("%d", &x) && x){
        if(x > 101)cout << x - 10 << endl;
        else cout << f[x] << endl;
    }
}