#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].name>>a[i].age>>a[i].score;
        cout<<a[i].name<<" "<<a[i].age+1<<" "<<min(600, a[i].score/5*6)<<endl;
    }

    return 0;
}