/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
class Rep{
    public:
        int x0,y0,x1,y1;
        bool color;
};
Rep rp[5007];
void resign(int &a,int &b){
    if(a>b){
        a=a^b;
        b=a^b;
        a=a^b;
    }
}
int main(){
    int i,j,k;
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        char c;
        scanf("%d %d %d %d %c",&rp[i].x0,&rp[i].y0,&rp[i].x1,&rp[i].y1,&c);
        resign(rp[i].x0,rp[i].x1);
        resign(rp[i].y0,rp[i].y1);
        if(c=='w') rp[i].color=false;
        else rp[i].color=true;
    }
    int ans=n*n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=m-1;k>=0;k--){
                if(rp[k].x0<=i && i<=rp[k].x1 && rp[k].y0<=j && j<=rp[k].y1){
                    if(rp[k].color){
                        ans--;
                    }
                    k=-1;
                }
            }
        }
    }
    printf("%d\n",ans);
}


