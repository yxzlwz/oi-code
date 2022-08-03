#include<iostream>
using namespace std;
int main(){
    double s, x;
    cin >> s >> x;
    double l = s - x, r = s + x;
    double speed = 7, p = 0;
    while(p < l){
        p += speed;
        speed *= 0.98;
    }
    if(p + speed > r)cout<<"n";
    else cout<<"y";

    return 0;
}