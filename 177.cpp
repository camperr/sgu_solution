/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
class Node{
    public:
        int value;
        int low,high;
};
class SegmentTree{
    public:
        Node tr[MAXN];
        int si;
        SegmentTree(){
            si=0;
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
class ST2{
    public:
    SegmentTree st2[MAXN];
    void build(int u,int v,int l,int r,int c){
        
    }
};

