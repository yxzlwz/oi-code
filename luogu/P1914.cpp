#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		s[i] += n;
		while(s[i] > 'z')s[i] -= 26;
	}
	cout<<s;

    return 0;
}