#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("D:/Desktop/P1567_4.in", "r", stdin);
    freopen("D:/Desktop/1.out", "w", stdout);
	int n,a[1000000],f=1,max1=-1;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int j=i;
		while(j<n-1 && a[j]<a[j+1]){
			f++;
			j++;
		}
		if(f>max1)max1=f;
		f=1;
	}
	cout<<max1;

    return 0;
}