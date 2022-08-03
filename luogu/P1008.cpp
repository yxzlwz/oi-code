#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans[3];
    int ram[999][3],len=0;
    bool out=0;
    memset(ram,0,sizeof(ram));
    for(int a1=1;a1<=9;a1++)
        for(int a2=1;a2<=9;a2++)
            for(int a3=1;a3<=9;a3++)
                for(int a4=1;a4<=9;a4++)
                    for(int a5=1;a5<=9;a5++)
                        for(int a6=1;a6<=9;a6++)
                            for(int a7=1;a7<=9;a7++)
                                for(int a8=1;a8<=9;a8++)
                                    for(int a9=1;a9<=9;a9++){
                                        out=1;
                                        if(a1!=a2&&a2!=a3&&a3!=a4&&a4!=a5&&a5!=a6&&a6!=a7&&a7!=a8&&a8!=a9){
                                            ans[0]=a1*100+a2*10+a3;
                                            ans[1]=a4*100+a5*10+a6;
                                            ans[2]=a7*100+a8*10+a9;
                                            sort(ans,ans+3);
                                            if(ans[0]*2==ans[1] && ans[0]*3==ans[2]){
                                                for(int i=0;i<len;i++){
                                                    if(ans[0]==ram[i][0] && ans[1]==ram[i][1] && ans[2]==ram[i][2]){
                                                        out=0;
                                                        break;
                                                    }
                                                }
                                                if(out){
                                                    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
                                                    ram[len][0]=ans[0];ram[len][1]=ans[1];ram[len][2]=ans[2];
                                                    len++;
                                                }
                                            }
                                        }
                                    }
    
    return 0;
}