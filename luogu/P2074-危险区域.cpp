#include<bits/stdc++.h>
using namespace std;

bool Map[10001][10001];
short move[8][2]={
    {1,0},{-1,0},{0,1},{0,-1},
    {1,1},{1,-1},{-1,1},{-1,-1}
};
int n,m,k,t;

struct zhadan{
    int x,y;
}a[100];

void dfs(int x, int y){
    for(int i=0;i<8;i++){
        int nx=x+move[i][0],
            ny=y+move[i][1];
        if(nx>=0&&nx<n&&ny>=0&&ny<m && sqrt(pow(abs(nx-x),2)+pow(abs(ny-y),2))<=t){
            Map[nx][ny]=1;
            dfs(nx,ny);
        }
    }
}

int main(){
    cin>>n>>m>>k>>t;
    for(int i=0;i<k;i++){
        int t1,t2;
        cin>>a[i].x>>a[i].y;
    }
    for(int i=0;i<k;i++){
        dfs(a[i].x, a[i].y);
    }
    cout<<"OK";

    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j])count++;
        }
    }
    cout<<count;

    return 0;
}