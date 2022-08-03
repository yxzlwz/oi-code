#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n == 1){
		cout<<1;
		return 0;
	}
	int a[100001]={n}, i=1;
	for(;;i++){
		if(n % 2 == 0){
			n /= 2;
		}else{
			n = n * 3 + 1;
		}
		a[i] = n;
		if(n == 1)break;
	}
	i++;
	while(i--){
		cout<<a[i]<<" ";
	}

	return 0;
}