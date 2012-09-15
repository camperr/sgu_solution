/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN=15007;
int n,bf[MAXN],cp[MAXN],cs[MAXN];
int add[MAXN],ls[MAXN],sum[MAXN],b;
void preprocess(){
    memset(ls,-1,sizeof(ls));
    int i;
    for(i=0;i<n;i++){
        int l=0,r=i-1,mid;
        while(l<=r){
            mid=(l+r)>>1;
            int tot=mid==0?sum[i]:(sum[i]-sum[mid-1]);
            if(tot>cp[i]){
                ls[i]=mid;
                l=mid+1;
            }else r=mid-1;
        }
    }
    memset(add,0,sizeof(add));
    b=0;
    for(i=0;i<n;i++){
        if(ls[i]==-1) b+=cs[i];
        else add[ls[i]]+=cs[i];
    }
}
void solve(){
    int i;
    int res=b,beg=0;
    for(i=1;i<n;i++){
        b=b-cs[i-1]+add[i-1];
        if(res>b) {
            res=b;
            beg=i;
        }
    }
    for(i=beg;i<n;i++){
        if(ls[i]<beg) printf("%d\n",i+1);
    } 
}

int main(){
    int i,j;
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d",bf+i,cp+i,cs+i);
        if(i==0) sum[i]=bf[i];
        else sum[i]=sum[i-1]+bf[i];
    }
    preprocess();
    solve();
}

