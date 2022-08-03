#include<cstdio>
#include<iostream>
#include<iomanip>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
int n;
cin>>n;
int i=1;
while(n>i){
	n-=i;
	i++;
}

int x,y,c,p;
if(i%2==0){
	x=1;y=i;c=1;p=1;
}else{
	x=i;y=1;c=1;p=-1;
}

while(c!=n){
	x+=p;y-=p;
	c++;
}
printf("%d/%d",x,y);



return 0;
}

