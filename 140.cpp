/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,p,b;
long long ar[107],g[107],x[107];
long long gcd(long long c,long long d){
    if(d==0) return c;
    else return gcd(d,c%d);
}
long long Eulid(long long c,long long d,long long r,long long &cx,long long &dx){
    if(d==0){
        cx=r/c;
        dx=0;
        return c;
    }
    long long eu=Eulid(d,c%d,r,cx,dx);
    long long temp=cx;
    cx=dx;
    dx=temp-c/d*dx;
    return eu;
}
int main(){
    long long i;
    freopen("in.txt","r",stdin);
    scanf("%I64d %I64d %I64d",&n,&p,&b);
    for(i=0;i<n;i++){
        scanf("%I64d",ar+i);
        if(i==0) g[i]=ar[i];
        else g[i]=gcd(g[i-1],ar[i]);
    }
    bool findSolution=false;
    long long cf=0;
    for(i=0;i<p;i++){
        if(g[n-1]*i%p==b){
            cf=i*g[n-1];
            findSolution=true;
            break;
        }
    }
    if(findSolution){
        long long cx,dx;
        for(i=n-1;i>0;i--){
            Eulid(g[i-1],ar[i],cf,cx,dx);
            cx=(cx%p+p)%p;
            dx=(dx%p+p)%p;
            x[i]=dx;
            if(i==1) x[i-1]=cx;
            else cf=cx*g[i-1];
        }
        printf("YES\n"); 
        for(i=0;i<n;i++){
            printf("%I64d",x[i]);
            if(i!=n-1) printf(" ");
            else printf("\n");
        }
    }else printf("NO\n");
}
