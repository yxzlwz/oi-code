#include<cstdio>
#include<iostream>
#include<iomanip>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
int n,a1,a2,b1,b2,c1,c2,a3,b3,c3,a4,b4,c4,ans;
cin>>n>>a1>>a2>>b1>>b2>>c1>>c2;
a3=n/a1+1;b3=n/b1+1;c3=n/c1+1;
a4=a3*a2;b4=b3*b2;c4=c3*c2;
ans=a4>b4?b4:a4;
ans=ans>c4?c4:ans;
cout<<ans;



return 0;
}

