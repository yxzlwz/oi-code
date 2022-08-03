#include<bits/stdc++.h>
using namespace std;

int hang[2001], lie[2001];

struct node{
    int num, cnt;
}hh[2001], ll[2001];

bool cmp(node a, node b){
    return a.cnt > b.cnt;
}
bool cmpp(node a, node b){
    return a.num < b.num;
}

int main(){
    int m, n, k, l, d;
    cin >> m >> n >> k >> l >> d;
    int t1, t2, t3, t4;
    for(int i = 0; i < d; i++){
        cin >> t1 >> t2 >> t3 >> t4;
        if(t1 == t3)lie[min(t2, t4)]++;
        else hang[min(t1, t3)]++;
    }

    int hhl = 0, lll = 0;
    for(int i = 1; i < m; i++)
        if(hang[i]){
            hh[hhl].num = i;
            hh[hhl++].cnt = hang[i];
        }
    for(int i = 1; i < n; i++)
        if(lie[i]){
            ll[lll].num = i;
            ll[lll++].cnt = lie[i];
        }
    sort(hh, hh + hhl, cmp);
    sort(hh, hh + k, cmpp);
    for(int i = 0; i < k; i++)cout << hh[i].num << " ";
    cout << endl;
    sort(ll, ll + lll, cmp);
    sort(ll, ll + l, cmpp);
    for(int i = 0; i < l; i++)cout << ll[i].num << " ";

    return 0;
}