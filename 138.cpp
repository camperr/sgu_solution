/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
struct pr{
    int no,v;
    bool operator <(const pr& ot)const{
        return v<ot.v;
    }
} v[107];
int res[10007][2];
int main(){
    int i,j,k,sum;
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=0,sum=0;i<n;i++) {
        scanf("%d",&v[i].v);
        v[i].no=i+1;
        sum+=v[i].v;
    }
    sum/=2;
    sort(v,v+n);
    memset(res,-1,sizeof(res));
    for(i=n-1,k=0;i>=0;i--){
        while(v[i].v>1 && k<sum){
            res[k++][0]=v[i].no;
            v[i].v--;
        }
        if(sum<=k) break;
        res[k][1]=v[i].no;
        v[i].v--;
    }
    for(i=sum-1;i>=0;i--){
        if(res[i][1]==-1){
            for(j=0;j<n;j++){
                if(v[j].v && v[j].no!=res[i][0]){
                    v[j].v--;
                    res[i][1]=v[j].no;
                    break;
                }
            }
        }
    }
    printf("%d\n",sum);
    for(i=0;i<sum;i++) printf("%d %d\n",res[i][0],res[i][1]);
}

