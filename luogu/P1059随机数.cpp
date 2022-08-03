#include<cstdio>
#include<iostream>
#include<iomanip>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
int n;cin>>n;
int in[n];
for(int i=0;i<n;i++)cin>>in[i];
int t[n],count=-1;
for(int i=0;i<n;i++){
	bool had=0;
	for(int j=0;j<i;j++){
		if(in[i]==t[j]){
			had=1;
			break;
		}
	}
	if(!had){
		t[++count]=in[i];
	}
}

cout<<count+1<<endl;
sort(t,t+count+1);
for(int i=0;i<count;i++)printf("%d ",t[i]);
cout<<t[count]; 

return 0;
}

