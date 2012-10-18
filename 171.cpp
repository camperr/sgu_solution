/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN=16007;
const int MAXM=107;
int k,n;
class Zone{
    public:
        int no;
        int a;
        int q;
        bool operator<(const Zone& ot)const{
            return q>ot.q;
        }
};
class Member{
    public:
        int no;
        int p;
        int w;
        bool operator<(const Member& ot)const{
            return w>ot.w;
        }
};
Zone z[MAXM];
Member mb[MAXN];
int zn[MAXN];
void read(){
    freopen("in.txt","r",stdin);
    int i,j;
    scanf("%d",&k);
    n=0;
    for(i=0;i<k;i++){
        scanf("%d",&z[i].a);
        z[i].no=i;
        n+=z[i].a;
    }
    for(i=0;i<k;i++){
        scanf("%d",&z[i].q);
    }
    sort(z,z+k);
    for(i=0;i<n;i++){
        scanf("%d",&mb[i].p);
        mb[i].no=i;
    }
    for(i=0;i<n;i++){
        scanf("%d",&mb[i].w);
    }
    sort(mb,mb+n);
    memset(zn,-1,sizeof(zn));
}
void solve(){
    int i,j;
    for(i=0;i<n;i++){
        int s=-1;
        for(j=0;j<k;j++){
            if(z[j].a>0 && z[j].q<mb[i].p){
                s=j;
                break;
            }
        }
        if(s==-1){
            for(j=0;j<k;j++){
                if(z[j].a>0){
                    s=j;
                    break;
                }
            }
        }
        zn[mb[i].no]=z[s].no;
        z[s].a--;
    }
    for(i=0;i<n;i++){
        printf("%d",1+zn[i]);
        if(i==n-1) printf("\n");
        else printf(" ");
    }
}
int main(){
    read();
    solve();
}

