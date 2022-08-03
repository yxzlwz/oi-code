#include<bits/stdc++.h>
using namespace std;

struct answer
{
    int count,place;
}ans;


int main(){
    char w[10],p[1000000];
    memset(w,' ',sizeof(w));memset(p,' ',sizeof(p));
    gets(w);gets(p);
    int lenw=strlen(w),lenp=strlen(p),place=0;
    cout<<p[0]<<p[1]<<p[2];
    for(int i=0;i<lenw;i++){
        if(w[i]<=90 && w[i]>=65)w[i]+=32;
    }
    for(int i=0;i<lenp;i++){
        if(p[i]<=90 && p[i]>=65)p[i]+=97;
    }
    puts(w);cout<<endl;puts(p);
    int i;
    bool have=1,had=0;
    ans.count=0;ans.place=0;
    
    while(place<=lenp){
        i=place;have=1;
        for(int j=0;j<lenw;j++){
            if(w[j]!=p[place++]){
                have=0;
                break;
            }
        }

        while(p[place++]!=' '){}
        while (p[place++]==' '){}
        

        if(have){
            ans.count++;
            if(had==0){
                ans.place=place-lenw-1;
                had=1;
            }
        }
    }

    if(had)cout<<ans.count<<' '<<ans.place;
    else cout<<-1;


    return 0;
}