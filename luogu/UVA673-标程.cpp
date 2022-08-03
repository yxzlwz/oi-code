#include<bits/stdc++.h>
using namespace std;

stack <char> s;
int num;

char trans(char c){
	switch (c)
	{
	case ')':
		return '(';
	case ']':
		return '[';
	case '}':
		return '{';
	default:
		return '\0';
	}
}

int main(){
	cin>>num;
	string p;
	getline(cin, p);
	while(num--){
		while(! s.empty()) s.pop();
		getline(cin, p);
		for(int i = 0; i < p.size(); i++){
			if(s.empty()){
				s.push(p[i]);
				continue;
			}
			if(trans(p[i]) == s.top()) s.pop();
			else s.push(p[i]);
		}
		if(s.empty()) cout<<"Yes\n";
		else cout<<"No\n";
	}

	return 0;
}
