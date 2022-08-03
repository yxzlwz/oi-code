#include<bits/stdc++.h>
using namespace std;

char x[1001], y[1001], z[1001];

int main(){
    int n;
    cin>>n;
    for(int i = 0; i< n;i++)cin >> x[i];
    for(int i = 0; i< n;i++)cin >> z[i];
    for(int i = 0; i < n;i++){
        if(z[i]>x[i]){
            cout<<-1;
            return 0;
        }
        if(z[i]<x[i])y[i] = z[i];
        else y[i] = 'z';
    }
    cout<<y;
}