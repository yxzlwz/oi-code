#include<bits/stdc++.h>
using namespace std;


int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    a = a * b / __gcd(a, b);
    a = a * c / __gcd(a, c);
    cout << a;

    return 0;
}