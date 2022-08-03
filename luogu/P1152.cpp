#include<bits/stdc++.h>
using namespace std;
int a[10000];
bool b[10000000];
int main(){
	int n;
	cin>>n;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		b[abs(a[i]-a[i-1])]=1;
	}
	for(int i=1;i<=n-1;i++){
		if(!b[i]){
			cout<<"Not jolly";
			return 0;
		}
	}
	cout<<"Jolly";
	return 0;
}
