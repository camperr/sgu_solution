#include<cstdio>
using namespace std;
int a[15];
int solve(int q){
    a[0]=5;
    //if(q==0) return 0;
    int i,c,res=-1;
    for(i=1;i<=12;i++) a[i]=a[i-1]*5;
    int l=1,r=1000000000,mid;
    while(l<=r){
        mid=(l+r)>>1;
        for(i=0,c=0;i<13;i++) c+=mid/a[i];
        if(c==q){
            res=mid;
            r=mid-1;
        }
        else if(c<q) l=mid+1;
        else r=mid-1;
    }
    return res;
}
int main(){
    int q,res;
    scanf("%d",&q);
    res=solve(q);
    if(res==-1) printf("No solution\n");
    else printf("%d\n",res);
}
