/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=128;
int cost[MAXN*MAXN];
class State{
    public:
        int g[MAXN][MAXN];
        State(){
            memset(g,-1,sizeof(g));
        }
        int* operator[](int a){
            return g[(a+MAXN)%MAXN];
        }
};
State s;
int n,m;
int min(int a,int b){
    if(a==-1) return b;
    else return a<b?a:b;
}
int main(){
    int i,j,k;
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",cost+i);
    }
    for(i=0;i<n;i++){
        for(j=1;j<m && j<=i;j++){
            if(i<m) s[i][j]=cost[i]+cost[i-j];
            else s[i][j]=s[i-j][m-j]+cost[i];
            if(j>1) s[i][j]=min(s[i][j-1],s[i][j]);
        }
    }
    int res=-1;
    for(i=n-1;n-i<m;i--){
        res=min(res,s[i][m-(n-i)]);
    }
    printf("%d\n",res);
}



