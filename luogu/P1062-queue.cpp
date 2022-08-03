#include<bits/stdc++.h>
using namespace std;

long long q[1000000], l =2, i = 1, j = 1;

int main(){
    int k, n;
    cin >> k >> n;
    q[1] = 1;
    q[2] = k;
    while(l <= n){
        long long x = q[i] * k, y = q[j] * k + 1;
        if(x < y){
            q[l++] = x;
            i++;
        }else{
            q[l++] = y;
            j++;
        }
    }
    cout<<q[n];

    return 0;
}