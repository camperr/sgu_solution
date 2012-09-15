/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXM=1007;
int n,m;
struct Node{
    int next,v;
};
class LinkList{
    public:
        int head[MAXM],si;
        Node list[MAXM*10];
        LinkList(){
            memset(head,-1,sizeof(head));
            si=0;
        }
        void addNode(int u,int v){
            list[si].next=head[u];
            list[si].v=v;
            head[u]=si++;
        }
};
LinkList lk;
int cnt[MAXM];
int dp[MAXM],tmp[MAXM];
int res[MAXM*10],last[MAXM*10];
int cntAns[MAXM];
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    int i,j,k,x;
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(x==m) x=0;
        cnt[x]++;
        lk.addNode(x,i+1);
    }
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    dp[1]=10*MAXM;
    for(i=1;i<m;i++){
        memcpy(tmp,dp,sizeof(dp));
        for(j=0;j<m;j++){
            if(tmp[j]!=-1){
                x=j;
                for(k=0;k<cnt[i];k++){
                    x=x*i%m;
                    if(dp[x]==-1 || dp[x]>i){
                        dp[x]=i;
                        last[x]=j;
                    }
                }
            }
        }
    }
    int f=-1;
//    for(i=0;i<m;i++) printf("%d ",dp[i]);
    memset(cntAns,0,sizeof(cntAns));
    for(i=m-1;i>0;i--){
        if(dp[i]!=-1){
            f=i;
            if(f==1 && dp[1]>n){
                printf("1\n");
                return 0;
            }
            k=i;
            while(true){
                x=last[k];
                while(x!=k){
                    cntAns[dp[k]]++;
                    x=x*dp[k]%m;
                }
                k=last[k];
                if(k==1) break;
            }
            break;
        }
    } 
    printf("%d\n",f);
    for(i=0,j=0;i<m;i++){
        for(k=0;k<cntAns[i];k++){
            x=lk.head[i];
            res[j++]=lk.list[x].v;
            lk.head[i]=lk.list[x].next;
        }
    }
    sort(res,res+j);
    for(i=0;i<j;i++){
        printf("%d",res[i]);
        if(i!=j-1) printf(" ");
        else printf("\n");
    }
}
