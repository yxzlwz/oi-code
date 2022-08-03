#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
//https://www.luogu.com.cn/problem/P1047

int l,m;
cin>>l>>m;
l+=1; 
int a[m],b[m],c[l];
for(int i=0;i<l;i++){c[i]=i;}
for(int i=0;i<m;i++){cin>>a[i];cin>>b[i];}

for(int i=0;i<m;i++){
	for(int j=a[i];j<b[i]+1;j++){
		c[j]=-1;
	}
}

int s=0;
for(int k=0;k<l;k++){
	if(c[k]>=0){
		s+=1;
	}
}


cout<<s;


return 0;
}

