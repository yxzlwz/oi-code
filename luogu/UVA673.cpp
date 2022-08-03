#include<bits/stdc++.h>
using namespace std;

stack <char> a;

int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		bool finish = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '[' || s[i] == '(') a.push(s[i]);
			else{
				if(a.empty() || (s[i] == ']' && a.top() != '[') || (s[i] == ')' && a.top() != '(')){
					finish = 1;
					cout<<"No\n";
					break;
				}else{
					a.pop();
				}
			}
		}
		if(!finish) cout<<"Yes\n";
	}

	return 0;
}
