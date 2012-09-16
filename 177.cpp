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
        int value;
        int low,high;
};
class SegmentTree{
    public:
        Node tr[MAXN];
        SegmentTree(){
            memset(tr,-1,sizeof(tr));
        }
        void build(int l,int r,int c){
            tr[c].low=l;
            tr[c].high=r;
            tr[c].val=0;
            if(l>=r) return;
            int mid=(l+r)>>1;
            build(l,mid,c<<1);
            build(mid+1,r,c<<1|1);
        }
        void update(int l,int r,int c,int val){
            if(l==tr[c].low && r==tr[c].high){
                tr[c].value=val;
                return;
            } 
            int mid=(tr[c].l+tr[c].r)>>1;
            if(r<=mid) update(l,r,c<<1,val);
            else if(l>mid) update(l,r,c<<1|1,val);
            else{
                update(l,mid,c<<1,val);
                update(mid+1,r,c<<1|1,val);
            }
        }
        int query(int l,int r,int c,int val){
            if(l==tr[c].low && r==tr[c].high){
                if(tr[c].val==val) return r-l+1;
                else return 0;
            }
            int mid=(tr[c].l+tr[c].r)>>1;
            if(r<=mid) return query(l,r,c<<1,val);
            else if(mid<l) return query(l,r,c<<1|1,val);
            else return query(l,mid,c<<1,val)+query(mid+1,r,c<<1|1,val);
        }
};
class Node2{
    public:
        SegmentTree st;
        int l,int r;
};

class ST2{
    public:
    Node2 st2[MAXN];
    void build(int u,int v,int l,int r,int c,int val){
        st2[c].l=u;
        st2[c].r=v;
        st2[c].build(l,r,1,val);
        if(u>=v) return;
        int mid=(u+v)>>1;
        build(u,mid,l,r,c<<1);
        build(mid+1,v,l,r,c<<1|1);
    }
    void update(int u,int v,int l,int r,int c,int val){
        if(st2[c].l==u && st2[c].r==v){
            st2[c].update(l,r,1,val);
            return;
        }
        int mid=(st2[c].l+st2[c].v)>>1;
        if(v<=mid) update(u,v,l,r,c<<1,val);
        else if(mid<u) update(u,v,l,r,c<<1|1,val);
        else{
            update(u,mid,l,r,c<<1,val);
            update(mid+1,v,l,r,c<<1|1,val);
        }
    }
    void query(int u,int v,int l,int r,int c,int val){
        if(st2[c].l==u && st2[c].r==v){
            return st2[c].query(l,r,1,val);
        }
        int mid=(st2[c].l+st2[c].r)>>1;
        if(v<=mid) return query(u,v,l,r,c<<1,val);
        else if(mid<u) return query(u,v,l,r,c<<1|1,val);
        else return query(u,mid,l,r,c<<1,val)+query(mid+1,v,l,r,c<<1|1,val);
    }
};
ST2 s2;
void makedata(){
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    s2.build(1,n,1,n,1,0);
    int i,k;
    int u,v,l,r;
    for(i=0;i<m;i++){
        char c;
        scanf("%d%d%d%d %c",&u,&v,&l,&r,&c);
        printf("%c\n",c);
        if(c=='w') k=0;
        else k=1;
        s2.update(u,v,l,r,1,k);
    }
}
int main(){
    makedata();
    printf("%d\n",s2.query(1,n,1,n,1,0));
}
