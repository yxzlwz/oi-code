#include<iostream>
using namespace std;
int main(){
	string a;
	string b;
	cin>>a;
	cin>>b;
	int la = a.length(), lb = b.length();
	int ansa = 1, ansb = 1;
	while(la--){
		ansa *= (a[la] - 'A' + 1);
	}
	while(lb--){
		ansb *= (b[lb] - 'A' + 1);
	}

	if((ansa%47) == (ansb%47))cout<<"GO";
	else cout<<"STAY";
	

	return 0;
}
