#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, d;
    scanf("%d/%d\n%d/%d", &a, &b, &c, &d);
    int e = a * c, f = b * d;
    for(int i = 2; i <= min(e, f); i++){
        while(e % i == 0 && f % i == 0){
            e /= i;
            f /= i;
        }
    }
    cout << f << " " << e;

    return 0;
}