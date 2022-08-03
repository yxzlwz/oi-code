#include <bits/stdc++.h>
using namespace std;

int n, m, t, sx, sy, fx, fy, a[11][11], ans;
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct node{
    int x, y, step;
} que[1000001];

void bfs(int p, int q){
    int head = 0, tail = 1;
    que[head].x = p;
    que[head].y = q;
    que[head].step = 0;
    a[p][q] = 1;
    while(head < tail){
        int x, y;
        for(int i = 0; i < 4; i++){
            x = que[head].x + mv[i][0];
            y = que[head].y + mv[i][1];
            if(x > 0 && y > 0 && x <= n && y <= m && !a[x][y]){
                que[tail].x = x;
                que[tail].y = y;
                que[tail].step = que[head].step + 1;
                a[x][y] = 1;
                tail++;
                if(x == fx && y == fy){
                    ans++;
                    a[x][y] = 0;
                }
                cout<<x<<" "<<y<<endl;
            }
        }
        head++;
    }
}

int main(){
    cin>>n>>m>>t>>sx>>sy>>fx>>fy;
    int a1, a2;
    while(t--){
        cin>>a1>>a2;
        a[a1][a2] = 1;
    }
    bfs(sx, sy);
    cout<<ans;
    return 0;
}