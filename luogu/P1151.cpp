#include<iostream>
using namespace std;
int main(){
    int k;
    cin >> k;
    bool out = 0;
    for(int i = 10000; i <= 30000; i++){
        int a1 = i / 100, a3 = i % 1000, a2 = (i / 10) % 1000;
            // cout << a1 << " "<<a2<<" "<<a3<<" ";
        if(!(a1 % k) && !(a2 % k) && !(a3 % k)){
            // cout << a1 << " "<<a2<<" "<<a3<<" ";
            cout << i << endl;
            out = 1;
        }
        // break;
    }
    if(!out)cout << "No";
    
    return 0;
}