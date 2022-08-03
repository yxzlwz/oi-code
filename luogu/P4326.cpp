#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double n, p = 3.14159265358979;
    cin >> n;
    cout << fixed << setprecision(6) << n * n * p << "\n" << n * n * 2.000;

    return 0;
}