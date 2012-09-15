/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN=10007;
int step[17];
bool dp[MAXN];
int n,m;
int findCycle(){
    int i,k;
    for(i=10;i<MAXN/2;i++){
        bool getIt=true;
        for(k=i;k<MAXN;k++){
            if(dp[k-i]!=dp[k]){
                getIt=false;
                break;
            }
        }
        if(getIt) return i;
    }
    return -1;
}
int main(){
    int i,j,k;
    freopen("in.txt","r",stdin);
    scanf("%d",&k);
    while(k--){
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++) scanf("%d",step+i);
        step[m]=1;
        dp[0]=false;
        for(i=1;i<MAXN;i++){
            bool first=true;
            for(j=0;j<=m;j++){
                if(i>=step[j] && dp[i-step[j]]==true){
                    first=false;
                    break;
                }
            }
            dp[i]=first;
        }
        int x=findCycle();
        printf("cycle count:%d\n",x);
        if(!dp[n%x]) printf("FIRST PLAYER MUST WIN\n");
        else printf("SECOND PLAYER MUST WIN\n");
    }

}

