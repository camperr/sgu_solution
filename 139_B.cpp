/*
 * Author:  nzh@UESTC
 * This solution cannot pass the judge.To see the AC code in 139.cpp
 */
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
bool findSolution;
int nextCostLimit;
int c[4][4];
bool check(){
    int i,j;
    int dis=0;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            dis+=abs(i-c[i][j]/4)+abs(j-c[i][j]%4);
    if(dis%2==1) return false;
    return true;
}
int dist(){
    int i,j;
    int dis=0;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(c[i][j]!=15)
                dis+=abs(i-c[i][j]/4)+abs(j-c[i][j]%4);
    return dis;
}
void dfs(int g,int costLimit,int x,int y){
    int d=dist();
    int cost=g+d;
    if(cost>costLimit){
        nextCostLimit=min(nextCostLimit,cost);
        return;
    }
    if(d==0){
        findSolution=true;
        return;
    }

    if(x){
        c[x][y]=c[x-1][y];
        c[x-1][y]=15;
        dfs(g+1,costLimit,x-1,y);
        c[x-1][y]=c[x][y];
        c[x][y]=15;
    }
    if(findSolution) return;
    if(y){
        c[x][y]=c[x][y-1];
        c[x][y-1]=15;
        dfs(g+1,costLimit,x,y-1);
        c[x][y-1]=c[x][y];
        c[x][y]=15;
    }
    if(findSolution) return;
    if(x<4){
        c[x][y]=c[x+1][y];
        c[x+1][y]=15;
        dfs(g+1,costLimit,x+1,y);
        c[x+1][y]=c[x][y];
        c[x][y]=15;
    }
    if(findSolution) return;
    if(y<4){
        c[x][y]=c[x][y+1];
        c[x][y+1]=15;
        dfs(g+1,costLimit,x,y+1);
        c[x][y+1]=c[x][y];
        c[x][y]=15;
    }
}
void ida(){
    int costLimit=dist();
    int L=costLimit+16;
    int x,y,i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(c[i][j]==15){
                x=i;
                y=j;
            }
        }
    }
    while(true){
        nextCostLimit=10007;
        dfs(0,costLimit,x,y);
        printf("%d\n",costLimit);
        if(findSolution || nextCostLimit>L) break;
        costLimit=nextCostLimit;
    }
}
int main(){
    int i,j;
    freopen("in.txt","r",stdin);
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            scanf("%d",c[i]+j);
            c[i][j]=(c[i][j]+15)%16;
        }
    }
    findSolution=false;
    if(check()) ida();
    if(findSolution) printf("YES\n");
    else printf("NO\n");
    return 0;
}
