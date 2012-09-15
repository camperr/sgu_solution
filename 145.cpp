/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=107;
const int MAXM=10007;
const int MAXV=1000000007;
int n,m,K;
int xs,xe;
int h[MAXN];
int si;
int head[MAXN];
struct pnt{
    int v,next,val;
};
pnt pt[MAXM];
int e;
void addNode(int u,int v,int val){
    pt[e].next=head[u];
    pt[e].v=v;
    pt[e].val=val;
    head[u]=e++;
}
bool close[MAXN];
void Dijkstra(){
    memset(h,-1,sizeof(h));
    h[xe]=0;
    int i,j,k;
    memset(close,false,sizeof(close));
    for(i=0;i<n;i++){
        k=-1;
        for(j=0;j<n;j++){
            if(close[j]==false && h[j]!=-1){
                if(k==-1 || h[j]<h[k]) k=j;
            }
        } 
        if(k==-1) break;
        close[k]=true;
        for(j=head[k];j!=-1;j=pt[j].next){
            int v=pt[j].v;
            if(h[v]==-1 || h[k]+pt[j].val<h[v]){
                h[v]=h[k]+pt[j].val;
            }
        }
    }
    for(i=0;i<n;i++) printf("%d ",h[i]);puts("");
}
bool vis[MAXN],terminal;
int path[MAXN],pathCount;
int costLimit,nextCostLimit;
int kthLength,siPath;
void idaStar(int c,int u,int nowCost){
    path[c]=u;
    if(u==xe){
        pathCount++;
        if(pathCount==K){
            terminal=true;
            kthLength=nowCost;
            siPath=c;
        }
        return;
    }
    int g=h[u]+nowCost;
    if(g>costLimit){
        if(nextCostLimit>g) nextCostLimit=g;
        return;
    }

    int i,k,v;
    for(i=head[u];i!=-1;i=pt[i].next){
        v=pt[i].v;
        if(!vis[v]){
            nowCost+=pt[i].val;
            vis[v]=true;
            idaStar(c+1,v,nowCost);
            nowCost-=pt[i].val;
            vis[v]=false;
            if(terminal) return;
        }
    }
}
void solve(){
    Dijkstra();
    memset(vis,false,sizeof(vis));
    terminal=false;
    costLimit=h[xs];
    vis[xs]=true;
    pathCount=0;
    while(!terminal){
        nextCostLimit=MAXV;
        idaStar(0,xs,0);
        costLimit=nextCostLimit;
        printf("costLimit:%d\n",costLimit);
    }
    int i;
    printf("%d %d\n",kthLength,siPath+1);
    for(i=0;i<=siPath;i++){
        printf("%d",path[i]+1);
        if(i==siPath) printf("\n");
        else printf(" ");
    }
}
int main(){
    int i,j;
    freopen("in.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&K);
    memset(head,-1,sizeof(head));
    for(i=0,e=0;i<m;i++){
        int u,v,val;
        scanf("%d %d %d",&u,&v,&val);
        u--,v--;
        addNode(u,v,val);
        addNode(v,u,val);
    }
    scanf("%d %d",&xs,&xe);
    xs--,xe--;
    solve();
}
