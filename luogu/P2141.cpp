#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];bool b[n][n];
    for(int i=0;i<n;i++)cin>>a[n];
    int count=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(i==k)continue;
            for(int j=0;j<n;j++){
                if(a[k]==a[i]+a[j] && k!=i && k!=j && b[j][i]==0){
                    b[i][j]=1;
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;

    return 0;
}