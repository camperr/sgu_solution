/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_TRY=1000000;
long long x1,x2,p,k;
long long a0,a1,b0,b1;
bool findSolution=false;
long long Euclid(long long x,long y,long long p,long long &a,long long &b){
    if(y==0){
        a=p/x;
        b=0;
        return x;
    }else{
        long long eu=Euclid(y,x%y,p,a,b);
        long long temp=a;
        a=b;
        b=temp-x/y*b;
        return eu;
    }
}
void cal(int a,int b){
    if((a+b+k)%2==0){
        b1=b>0?0:-b;
        b0=b1+b;
        a1=(k-a-b)/2-b1;
        a0=a1+a;
        if(a1>=0 && a0>=0){
            findSolution=true;
            return;
        }
    }
}
int main(){
    freopen("in.txt","r",stdin);
    scanf("%lld %lld %lld %lld",&x1,&x2,&p,&k);
    long long a,b;
    long long step=Euclid(x1,x2,p,a,b);
    int i;
    for(i=0;i<MAX_TRY;i++){
        cal(a+i*x2/step,b-i*x1/step);
        if(findSolution) break;
        cal(a-i*x2/step,b+i*x1/step);
        if(findSolution) break;
    }
    if(p%step==0 && findSolution){
        printf("YES\n");
        printf("%I64d %I64d %I64d %I64d\n",a0,a1,b0,b1); 
        printf("%lld %lld %lld %lld\n",a0,a1,b0,b1);
    }else printf("NO\n");
}

