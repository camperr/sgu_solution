/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN=3000;
int n,m;
class Node{
    public:
        int val;
        int low,high;
};
class SegmentTree{
    public:
        Node tr[MAXN];
        SegmentTree(){
            memset(tr,-1,sizeof(tr));
        }
        void push(int c){
            if(tr[c].val!=-1){
                tr[c<<1].val=tr[c<<1|1].val=tr[c].val;
                tr[c].val=-1;
            }
        }
        void pull(int c){
            if(tr[c<<1].val!=-1 && tr[c<<1].val==tr[c<<1|1].val){
                tr[c].val=tr[c<<1].val;
            }     
        }
        void build(int l,int r,int c,int val){
            tr[c].low=l;
            tr[c].high=r;
            tr[c].val=val;
            if(l>=r) return;
            int mid=(l+r)>>1;
            build(l,mid,c<<1,val);
            build(mid+1,r,c<<1|1,val);
        }
        void update(int l,int r,int c,int val){
            if(l==tr[c].low && r==tr[c].high){
                tr[c].val=val;
                return;
            } 
            if(tr[c].low<=l && r<=tr[c].high && tr[c].val==val) return;
            int mid=(tr[c].low+tr[c].high)>>1;
            push(c);
            if(r<=mid) update(l,r,c<<1,val);
            else if(l>mid) update(l,r,c<<1|1,val);
            else{
                update(l,mid,c<<1,val);
                update(mid+1,r,c<<1|1,val);
            }
            pull(c);
        }
        int query(int val,int c){
            if(tr[c].val!=-1){
                if(tr[c].val==val) return tr[c].high-tr[c].low+1;
                else return 0;
            }else return query(val,c<<1)+query(val,c<<1|1);
        }
};
SegmentTree st[MAXN];
int cal(){
    int i,k;
    for(k=0,i=1;i<=n;i++){
        k+=st[i].query(0,1);
    }
    return k;
}
void swap(int &u,int &v){
    u^=v;
    v^=u;
    u^=v;
}
int main(){
    freopen("in.txt","r",stdin);
    int i,j,k;
    scanf("%d %d",&n,&m);
    int rl,rr,cl,cr;
    char c;
    for(i=1;i<=n;i++) {
        st[i].build(1,n,1,-1);
        st[i].tr[1].val=0;
    }
    for(i=0;i<m;i++){
        scanf("%d%d%d%d %c",&rl,&rr,&cl,&cr,&c);
        if(c=='w') k=0;
        else k=1;
        if(rl>cl) swap(rl,cl);
        if(rr>cr) swap(rr,cr);
        for(j=rl;j<=cl;j++) st[j].update(rr,cr,1,k);
    }
    k=cal();
    printf("%d\n",k);
}
