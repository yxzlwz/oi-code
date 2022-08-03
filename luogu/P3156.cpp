#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++){
		cin>>n;
		cout<<a[n-1]<<endl;
	}

	return 0;
}
