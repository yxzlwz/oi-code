#include<bits/stdc++.h>
using namespace std;

struct node{
    int p, a;
}z[1000001];

bool cmp(node a, node b){
    return a.p < b.p;
}

int main(){
    int n, m;
    cin >> m>>n;
    for(int i = 0; i < n; i++)cin >> z[i].p >> z[i].a;
    sort(z, z + n, cmp);
    int summ = 0, i = 0;
    while(m){
        if(m >= z[i].a){
            m -= z[i].a;
            summ += z[i].a * z[i].p;
        }
        else{
            summ += m * z[i].p;
            m = 0;
        }
        i++;
    }

    cout << summ;

    return 0;
}