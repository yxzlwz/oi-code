#include<bits/stdc++.h>
using namespace std;
int main(){
	int x1, y1, x2, y2;
	cin>>x1>>y1>>x2>>y2;
	int t;
	cin>>t;
	int cnt = 0;
	for(int i=0;i<t;i++){
		int nx, ny;
		char d;
		cin>>d;
		switch(d){
		case 'N':
			nx=0;
			ny=1;
			break;
		case 'S':
			nx=0;
			ny=-1;
			break;
		case 'E':
			nx=1;
			ny=0;
			break;
		case 'W':
			nx=-1;
			ny=0;
			break;
		}
		if(x2-x1>x2-(x1+nx) || y2-y1>y2-(y1+ny)){
			x1 += nx;
			y1 += ny;
		}
		cnt++;
		if(x1==x2 && y1==y2){
			cout<<cnt;
			return 0;
		}
	}
	cout<<-1;

	return 0;
}
