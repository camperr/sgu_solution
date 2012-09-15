/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN=400007;
const int HASH_BASE=100007;
int m;
class Edge{
    public:
        int next;
        int anc;
        int x;
        int y;
};
int getHashVal(int x,int y){
    long long c=x,d=y;
    long long s=(c*c*2%HASH_BASE+d*d%HASH_BASE)%HASH_BASE;
    return (int)s;
}
class LinkList{
    public:
        int head[HASH_BASE+7];
        int si;
        Edge ed[MAXN];
        LinkList(){
            memset(head,-1,sizeof(head));
            si=0;
        }
        void addEdge(int x,int y){
            int u=getHashVal(x,y);
            ed[si].next=head[u];
            ed[si].x=x;
            ed[si].y=y;
            ed[si].anc=si;
            head[u]=si++;
        }
        int find(int x,int y){
            int u=getHashVal(x,y);
            int i;
            for(i=head[u];i!=-1;i=ed[i].next){
                if(ed[i].x==x && ed[i].y==y)
                return i;
            }
            return -1;
        }
};
LinkList lk;
int getAnc(int q){
    if(q==lk.ed[q].anc) return q;
    else{
        int t=getAnc(lk.ed[q].anc);
        lk.ed[q].anc=t;
        return t;
    }
}
bool unionPoint(int x0,int y0,int x1,int y1){
    int h0=lk.find(x0,y0);
    if(h0==-1){
        lk.addEdge(x0,y0);
        h0=lk.si-1;
    }
    int h1=lk.find(x1,y1);
    if(h1==-1){
        lk.addEdge(x1,y1);
        h1=lk.si-1;
    }
    int a0=getAnc(h0);
    int a1=getAnc(h1);
    if(a0==a1) return true;
    lk.ed[a0].anc=a1;
    return false;
}
int main(){
    int i,j;
    freopen("in.txt","r",stdin);
    scanf("%d",&m);
    int x0,y0,x1,y1;
    int res=0;
    for(i=0;i<m;i++){
        scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
        if(unionPoint(x0,y0,x1,y1)){
            res=i+1;
            break;
        }
    }
    printf("%d\n",res);
}

