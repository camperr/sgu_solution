#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN=10007;
struct ver{
    int v,l;
};
vector<ver> conn[MAXN];
int n,maxDist,disPoint;
int res[MAXN];
bool vis[MAXN];
void dfs(int u,int dis){
    vis[u]=true;
    int i;
    int si=conn[u].size();
    for(i=0;i<si;i++){
        int v=conn[u][i].v;
        if(!vis[v]){
            dis+=conn[u][i].l;
            if(maxDist<dis){
                maxDist=dis;
                disPoint=v;
            }
            res[v]=res[v]<dis?dis:res[v];
            dfs(v,dis);
            dis-=conn[u][i].l;
        }
    }
}
int main(){
    int i,j,k;
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    int u,v;
    ver m;
    for(i=1;i<n;i++){ 
        scanf("%d %d",&m.v,&m.l);
        m.v--;
        conn[i].push_back(m);
        u=m.v;
        m.v=i;
        conn[u].push_back(m);
    }
    int b=0;
    for(i=0;i<4;i++){
        memset(vis,false,sizeof(vis));
        dfs(b,0);
        b=disPoint;
    }
    for(i=0;i<n;i++) printf("%d\n",res[i]);
}
