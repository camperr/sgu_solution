#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1007;
bool conn[MAXN][MAXN];
bool vis[MAXN];
int deg[MAXN];
struct ver{
    int l,r;
} res[MAXN];
int n,beg,end,r;
char s[10*MAXN];
void updateDeg(int a){
    int i;
    for(i=1;i<=n;i++){
        if(vis[i] && i!=a && conn[i][a]){
            deg[i]--;
            deg[a]--;
        }
    }
}
void dfs(int a,int b){
    int i;
    bool lger=false;
    for(i=1;i<=n;i++){
        if(!vis[i] && conn[i][a]){
            res[i].r=a;
            res[a].l=i;
            lger=true;
            vis[i]=true;
            a=i;
            r++;
            updateDeg(i);
            break;
        }
    }
    for(i=1;i<=n;i++){
        if(!vis[i] && conn[b][i]){
            res[b].r=i;
            res[i].l=b;
            vis[i]=true;
            lger=true;
            b=i;
            r++;
            updateDeg(i);
            break;
        }
    }
    if(lger) dfs(a,b);
    else {
        beg=a;
        end=b;
    }
}
void findCycle(){
        int i,j;
        for(i=end;i!=beg;i=res[i].l){
            j=res[i].l;
            if(conn[beg][i] && conn[end][j]) break;
        }
        res[j].r=end;
        for(int u=end;u!=i;u=res[u].r){
            res[u].r=res[u].l;
            res[u].l=j;
            j=u;
        }
        res[i].l=j;
        res[i].r=beg;
        res[beg].l=i;
}
void cutCycle(){
    int i,j;
    for(i=beg;;i=res[i].l){
        if(deg[i]){
            for(j=1;j<=n;j++){
                if(!vis[j] && conn[i][j]){
                    beg=res[i].r;
                    res[beg].l=0;
                    end=j;
                    res[j].l=i;
                    res[i].r=j;
                    vis[j]=true;
                    r++;
                    updateDeg(j);
                    break;
                }
            }
            break;
        }
    }
}
int main(){
    freopen("in.txt","r",stdin);
    int i,j,k,si;
    memset(res,0,sizeof(res));
    memset(deg,0,sizeof(deg));
    memset(conn,false,sizeof(conn));
    memset(vis,false,sizeof(vis));
    scanf("%d",&n);getchar();
    for(i=1;i<=n;i++){
        j=0,k=0;
        gets(s);
        si=strlen(s);
        for(j=0;j<=si;j++){
            if(j<si && s[j]>='0' && s[j]<='9')
                k=k*10+s[j]-'0';
            else{
                if(k) {
                    deg[i]++;
                    conn[i][k]=true;
                    //printf("%d",k);
                    }
                k=0;
            }
        }
    }
    r=1;
    vis[1]=true;
    dfs(1,1);
    //printf("  r:%d beg:%d end:%d\n",r,beg,end);
    while(r<n){
        //printf("%d\n",r);
        findCycle();
        cutCycle();
        dfs(beg,end);
    }
    findCycle();
    for(i=1,j=0;j<n;i=res[i].l,j++) printf("%d ",i);
    printf("1\n");
}
