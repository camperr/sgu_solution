/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN=70007;
int n;
struct pr{
        int x,y,no;
        bool operator<(const pr&ot)const{
            return x<ot.x;
        }
};
pr ps[MAXN];
struct node{
    int z,l,r;
};
class SegmentTree{
    public:
        node set[MAXN*2];
        int si;
        SegmentTree(){
            memset(set,0,sizeof(set));
        }
        int build(int l,int r,int c){
            set[c].l=l;
            set[c].r=r;
            if(l==r){
                set[c].z=l;
                return l;
            }
            int mid=(l+r)>>1;
            int lMin=build(l,mid,c*2);
            int rMin=build(mid+1,r,c*2+1);
            if(ps[lMin].y<ps[rMin].y) set[c].z=lMin;
            else set[c].z=rMin;
            return set[c].z;
        }
        int getMin(int u,int v,int c){
            printf("%d %d %d %d %d\n",u,v,c,set[c].l,set[c].r);
            if(u==set[c].l && v==set[c].r) return set[c].z;
            int mid=(set[c].l+set[c].r)>>1;
            if(v<=mid) return getMin(u,v,c*2);
            else if(u>mid) return getMin(u,v,c*2+1);
            else{
                int lMin=getMin(u,mid,c*2);
                int rMin=getMin(mid+1,v,c*2+1);
                if(ps[lMin].y<ps[rMin].y) return lMin;
                else return rMin;
            }
        }
};
SegmentTree st;
void doPreprocess(){
    sort(ps+1,ps+n+1);
    st.build(1,n,1);
}
int findMin(int l,int r){
    int i,k;
    for(i=l,k=l;i<=r;i++){
        if(ps[i].y<ps[k].y)k=i;
    }
    return k;
}
struct tree{
    int no,p,ls,rs;
};
tree tr[MAXN];
int dfs(int l,int r,int d){
    if(l>r) return 0;
    if(l==r){
        int k=ps[l].no;
        tr[k].p=d;
        tr[k].ls=tr[k].rs=0;
        return k;
    }
    int g=st.getMin(l,r,1);
    int k=ps[g].no;
    tr[k].p=d;
    tr[k].ls=dfs(l,g-1,k);
    tr[k].rs=dfs(g+1,r,k);
    return k;
}
void solve(){
    dfs(1,n,0);
    int i;
    printf("YES\n");
    for(i=1;i<=n;i++){
        printf("%d %d %d\n",tr[i].p,tr[i].ls,tr[i].rs);
    }
}
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d %d",&ps[i+1].x,&ps[i+1].y);
        ps[i+1].no=i+1;
    }
    doPreprocess();
    solve();
}
