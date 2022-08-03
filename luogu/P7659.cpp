#include<iostream>
using namespace std;
int main(){
    int a[8];
    for(int i = 0; i < 8; i++){
        cin >> a[i];
    }
    int maxx = 0;
    for(int i = 0; i < 8; i++){
        int cnt = 0;
        for(int j = 0; j < 4; j++){
            cnt += a[(i + j) % 8];
        }
        if(cnt > maxx)maxx = cnt;
    }
    cout<<maxx;
    return 0;
}