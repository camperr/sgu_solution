/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <cstring>
using namespace std;
long long n;
int main(){
    freopen("in.txt","r",stdin);
    scanf("%I64d",&n);
    long long res=0;
    long long low=0,high=n;
    while(low<=high){
        long long mid=(low+high)>>1;
        long long k=mid;
        bool yes=false;
        for(long long i=0;i<mid+1;i++){
            k=k*2+1;
            if(k>=n){
                yes=true;
                break;
            }
        }
        if(yes){
            high=mid-1;
            res=mid;
        }else{
            low=mid+1;
        }
    }
    printf("%I64d\n",res);
}
