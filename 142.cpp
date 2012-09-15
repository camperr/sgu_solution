/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=500007;
char sr[MAXN];
int n;
bool vis[2*MAXN];
int main(){
    int i,j,k;
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    scanf("%s",sr);
    int maxL=19,minL=1;
    maxL=maxL<n?maxL:n;
    int mid,ans,ansL,x;
    while(minL<=maxL){
        mid=(minL+maxL)/2;
        bool yes=false;
        k=1<<mid;
        memset(vis,false,sizeof(vis));
        for(i=0,x=0;i<mid;i++) x=x*2+sr[i]-'a';
        vis[x]=true;
        for(i=1;i<n-mid+1;i++){
            x=x%(k/2)*2+sr[i+mid-1]-'a';
            vis[x]=true;
        }
        for(i=0;i<k;i++){
            if(!vis[i]){
                ans=i;
                ansL=mid;
                yes=true;
                break;
            } 
        }
        if(yes) maxL=mid-1;
        else minL=mid+1;
    }
    k=1<<ansL-1;
    char res[27];
    for(i=0;i<ansL;i++){
        res[i]='a'+ans/k;
        ans=ans%k;
        k>>=1;
    }
    res[ansL]='\0';
    printf("%d\n",ansL);
    printf("%s\n",res);
}
