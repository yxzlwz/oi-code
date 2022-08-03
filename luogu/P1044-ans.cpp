#include<iostream>
using namespace std;

int f[1001][1001];

int main(){
    int n;
    cin >> n;
    // i个数字还未输出，且其中j个数未入栈
    for(int i = 1; i <= n; i++){
        f[i][0] = 1;  // j=0，所有未输出的都已经入栈，因此只有一种
        for(int j = 1; j <= i; j++){
            // 若选择弹出栈中元素，则有f(i - 1, j)种可能
            // 若选择入栈一个元素，则有f(i, j - 1)种可能
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    cout << f[n][n];
}