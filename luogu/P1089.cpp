#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[12];
	for(int i=0;i<12;i++)cin>>a[i];
	int bank = 0, mine = 0;
	for(int i=0;i<12;i++){
		mine += 300;
		mine -= a[i];
		if(mine < 0){
			cout<<"-"<<i+1;
			return 0;
		}
		if(mine > 100){
			bank += 100 * (mine / 100);
			mine %= 100;
		}
	}
	cout<<mine + bank * 1.2;

	return 0;
}