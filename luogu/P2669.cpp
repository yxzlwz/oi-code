#include<iostream>
using namespace std;
int main()
{
int k;
cin>>k;
int ans=0;
int i=1;
while(k-i>0){
    ans+=i*i;
    k-=i;
    i++;
}
ans+=k*i;
cout<<ans;


}