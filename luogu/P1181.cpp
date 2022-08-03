#include<bits/stdc++.h>
using namespace std;
int a, b;
int n[10001];
int main(){
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    int sum[10001], cnt=0;
    for(int i=0;i<a;i++){
        bool finish=0;
        for(int j=0;j<cnt;j++){
            if(sum[j]+n[i]<=b){
                sum[j]+=n[i];
                finish = 1;
            }
        }
        if(!finish){
            cnt++;
            sum[cnt] = n[i];
        }
    }
    cout<<cnt+1;
}