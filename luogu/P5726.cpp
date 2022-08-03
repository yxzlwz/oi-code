#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	short a[10001];
	int Max=-1, Min=11;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>Max)Max = a[i];
		if(a[i]<Min)Min = a[i];
	}
	bool Maxed=0, Mined=0;
	int s=0;
	for(int i=0;i<n;i++){
		if(a[i]==Max && (!Maxed)){
			Maxed = !Maxed;
			continue;
		}
		if(a[i]==Min && (!Mined)){
			Mined = !Mined;
			continue;
		}
		s += a[i];
	}
	//cout<<s<<endl;
	cout<<fixed<<setprecision(2)<<double(s) / double(n-2);

	return 0;
}
