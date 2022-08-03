#include<bits/stdc++.h>
using namespace std;
int m[10001], c[10001], f[10001][10001];
int main(){
	int t, M;
	cin>>t>>M;
	for(int i=1;i<=M;i++)cin>>m[i]>>c[i];
	for(int i=1;i<=M;i++){
		for(int j=1;j<=t;j++){
			if(j-m[i] < 0)f[i][j] = f[i-1][j];
			else f[i][j] = max(f[i-1][j], f[i-1][j-m[i]]+c[i]);
		}
	}
	cout<<f[M][t];

	return 0;
}
