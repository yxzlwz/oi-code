#include<bits/stdc++.h>
using namespace std;
float dis(float x1,float y1,float x2,float y2){
    return sqrt(pow((x2-x1),2) + pow((y2-y1),2));
}

int main(){
    float a1,a2,a3,a4,a5,a6;
    cin>>a1>>a2>>a3>>a4>>a5>>a6;
    cout<<fixed<<setprecision(2)<<dis(a1, a2, a3, a4) + dis(a1, a2, a5, a6) + dis(a3, a4, a5, a6);

    return 0;
}