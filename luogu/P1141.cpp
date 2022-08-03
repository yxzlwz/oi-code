#include<bits/stdc++.h>
using namespace std;

int n, m;
bool a[1001][1001];
int visited[1001][1001];
int ans[1000001], d;
short mv[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct node{
    int x, y;
} que[1000001];

void bfs(int p, int q){
    d++;
    ans[d]++;
    int head = 0, tail = 1;
    que[head].x = p;
    que[head].y = q;
    visited[p][q] = d;
    int x, y;
    while(head < tail){
        for(int i = 0; i < 4; i++){
            x = que[head].x + mv[i][0];
            y = que[head].y + mv[i][1];
            if(x > 0 && y > 0 && x <= n && y <= n && a[x][y] != a[que[head].x][que[head].y] && !visited[x][y]){
                ans[d]++;
                que[tail].x = x;
                que[tail].y = y;
                visited[x][y] = d;
                tail++;
            }
        }
        head++;
    }
}

int main(){
    // freopen("D:/Desktop/P1141_9.in", "r", stdin);
    // freopen("D:/Desktop/1.out", "w", stdout);
    cin >> n >> m;
    char c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    for(int i = 0; i < m; i++){
        int k, l;
        cin >> k >> l;
        if(!visited[k][l])
            bfs(k, l);
        cout << ans[visited[k][l]] << endl;
    }

    return 0;
}
