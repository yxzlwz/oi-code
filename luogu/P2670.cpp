#include<iostream>
#include<cstdio>
using namespace std;
int x[8]={-1,0,1,-1,1,-1,0,1};
int y[8]={-1,-1,-1,0,0,1,1,1};
int main(){
    int m,n;
    cin>>m>>n;
    char a[m+1][n+1];
    for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j]; 
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
        	if(a[i][j]=='*')continue;
            char count='0';
            for(int k=0;k<8;k++){
                if(i+x[k]>=1&&j+y[k]>=1 && i+x[k]<=m&&j+y[k]<=n  &&  a[i+x[k]][j+y[k]]=='*')
                    count+=1;
            }
            a[i][j]=count;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            cout<<a[i][j];
        cout<<endl;
    }
}
