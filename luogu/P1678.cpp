#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, sum = 0;
    cin >> m >> n;
    int school[100001];
    for(int i = 1; i <= m; i++)cin >> school[i];
    school[0] = school[m + 1] = 1000000;
    sort(school + 1, school + m + 1);
    while(n--){
        int score;
        cin >> score;
        int l = 1, r = m;
        while(l <= r){
            int mid = (l + r) / 2;
            if(score < school[mid] )r = mid - 1;
            else l = mid + 1;
        }
        sum += min(abs(score - school[l]), min(abs(score - school[l - 1]), abs(score - school[l + 1])));
        // cout << l<<" "<<sum <<endl;
    }
    cout << sum <<endl;

    return 0;
}