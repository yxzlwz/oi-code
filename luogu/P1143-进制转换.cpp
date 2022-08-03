#include<bits/stdc++.h>
using namespace std;

string a;

int main(){
    int n,m;
    cin>>n;
    cin>>a;
    cin>>m;

    int num[100000], len=a.length();
    for(int i=0;i<len;i++){
        num[i]=int(a[len-i-1])-48;
        if(num[i]>=10)num[i]-=7;
    }

    int sum=0;
    for(int i=0;i<len;i++){
        sum+=num[i]*pow(n,i);
    }

    char out[100000];
    len=0;
    while(sum){
        out[len]=sum%m+48;
        if(out[len]>=58)out[len]=out[len]+7;
        sum/=m;
        len++;
    }
    for(int i=len-1;i>=0;i--)cout<<out[i];
    //cout<<sum<<endl<<endl<<endl;

    //cout<<n<<endl<<a<<endl<<m;
    return 0;
}