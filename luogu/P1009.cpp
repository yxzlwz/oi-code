#include<iostream>
using namespace std;
int main(){
	int n;
	long long a;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long b=1;
		for(int j=1;j<=i;j++){
			b*=j;
		}
		a+=b;
	}
	cout<<a;

	return 0;
}
