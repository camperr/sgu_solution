/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[77][2200];
bool grid[77][10];
bool rw[10];
int n,m;
int sInit,arLast[10];
int min(int a,int b){
    if(a==-1) return b;
    else return a<b?a:b;
}
void trans(int a,int s){
    sInit=0;
    int t=1;
    for(int i=0;i<n;i++){
        arLast[i]=s%3;
        if(arLast[i]!=2) rw[i]=false;
        else rw[i]=true;
        if(grid[a][i]){
            sInit+=2*t;     
        }else if(arLast[i]==2) sInit+=t;
        t*=3;
        s/=3;
    }
}
bool valid(){
    for(int i=0;i<n-1;i++){
        if(rw[i]==false && rw[i+1]==false) return false;
    }
    return true;
}
int pow3[10];
void calPow3(){
    pow3[0]=1;
    for(int i=1;i<8;i++) pow3[i]=pow3[i-1]*3;
}
bool val;
void dfs(int a,int x,int s,int d){
    if(x>=n){
        if(valid()) dp[a][s]=min(dp[a][s],d);
        return;
    }
    if(arLast[x]==0){
        if(grid[a][x]){
            val=false;
            return;
        }
        rw[x]=true;
        dfs(a,x+1,s+2*pow3[x],d+1);
        rw[x]=false;
        return;
    }
    if(val && grid[a][x]==false){
        if(arLast[x]==1){
            rw[x]=true;
            dfs(a,x+1,s+2*pow3[x],d+1);
            rw[x]=false;
        }
        if(x<n-1 && grid[a][x+1]==false && arLast[x+1]!=0){
            int t=s;
            if(arLast[x]==1) t+=2*pow3[x];
            else t+=pow3[x];
            if(arLast[x+1]==1) t+=2*pow3[x+1];
            else t+=pow3[x+1];
            dfs(a,x+2,t,d+1);
        }
    }
    if(val) dfs(a,x+1,s,d);
}

int main(){
    int i,j,k;
    freopen("in.txt","r",stdin);
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++){
        char ss[100];
        scanf("%s",ss);
        for(j=0;j<n;j++){
            if(ss[j]=='*') grid[i][j]=true;
            else grid[i][j]=false;
        }
    }
    calPow3();
    int c=1;
    for(i=0;i<n;i++) c*=3;
    c-=1;val=true;
    memset(dp,-1,sizeof(dp));
    trans(0,c);
    dfs(0,0,sInit,0);
    i=0;
    while(true){
        for(j=0;j<=c;j++){
            if(dp[i][j]!=-1){
                trans(i+1,j);
                val=true;
                dfs(i+1,0,sInit,dp[i][j]);
            }
        }      
        i++;
        if(i==m) break;
    }
    int res=-1;
    for(i=0;i<=c;i++){
        trans(m-1,i);
        val=true;
        for(j=0;j<n;j++){
            if(arLast[j]==0){
                val=false;
                break;
            }
        }
        if(val && valid() && dp[m-1][i]!=-1){
            res=min(res,dp[m-1][i]);
        }
    }
    printf("%d\n",res);
}
