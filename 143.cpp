/*
 * ======================================
 *         Author:  nzh@uestc
 * ======================================
 */
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=16007;
int n;
int prf[MAXN];
struct edge{
    int v,next;
};
int head[MAXN],pointOfEdge;
edge e[2*MAXN];
bool vis[MAXN];
int maxPrf;
void addEdge(int u,int v){
    edge t;
    t.v=v;
    t.next=head[u];
    e[pointOfEdge]=t;
    head[u]=pointOfEdge++;
}
int dfs(int u){
    vis[u]=true;
    int i;
    int c=prf[u];
    for(i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(!vis[v]){
            int p=dfs(v);
            if(p>0) c+=p;
        }
    }
    maxPrf=max(maxPrf,c);
    return c;
}
int main(){
    int i;
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",prf+i); 
    }
    pointOfEdge=0;
    memset(head,-1,sizeof(head));
    for(i=0;i<n-1;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        v--,u--;
        addEdge(u,v);
        addEdge(v,u);
    }
    maxPrf=-20000000;
    memset(vis,false,sizeof(vis));
    dfs(0);
    printf("%d\n",maxPrf);

}


