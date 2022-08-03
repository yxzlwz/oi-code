#include<bits/stdc++.h>
using namespace std;
short m[1000001], c[1000001];
//int f[1001][100001];
int k[1000001];
int main(){
	int t, M;
	cin>>t>>M;
	for(int i=1;i<=M;i++)cin>>m[i]>>c[i];
//	for(int i=1;i<=M;i++){
//		for(int j=1;j<=t;j++){
//			if(j-m[i] < 0)f[i][j] = f[i-1][j];
//			else f[i][j] = max((int)f[i-1][j], f[i][j-m[i]]+c[i]);
//		}
//	}
    for(int i=1;i<=M;i++)
        for(int v=m[i];v<=t;v++)
            if(k[v-m[i]]+c[i]>k[v])  k[v]=k[v-m[i]]+c[i];
//	cout<<f[M][t];
	cout<<k[t];

	return 0;
}
