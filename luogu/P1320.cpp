#include<bits/stdc++.h>
using namespace std;
int main(){
	string s="", t;
	cin>>t;
	int 	len = t.length();
	cout<<len;
	s = s + t;
	for(int i=1;i<len;i++){
		cin>>t;
		s = s + t;
	}
	char last='0';
	int cnt = 0;
	for(int i=0;i<len*len;i++){
		if(s[i] == last)cnt++;
		else{
			cout<<" "<<cnt;
			last = s[i];
			cnt = 1;
		}
	}
	if(cnt)cout<<" "<<cnt;

	return 0;
}
