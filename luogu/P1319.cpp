#include<bits/stdc++.h>
using namespace std;

int n, Sum=0, cnt=0, ch=0;

void print(char a){
	cout<<a;
	cnt++;
	if(cnt == n){
		cout<<endl;
		cnt=0;
	}
}

int main(){
	cin>>n;
	while(Sum != n*n){
		int t;
		cin>>t;
		Sum+=t;
		for(;t>0;t--){
			if(ch % 2)print('1');
			else print('0');
		}
		ch++;
		//cout<<Sum<<endl;
	}

	return 0;
}