/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=6007;
const double eps=1e-8;
int n;
double hi[MAXN];
int res[MAXN];
int main(){
    freopen("in.txt","r",stdin);
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%lf",hi+i);
        hi[i]-=2.00;
    }
    double s=0;
    for(i=0,j=0,k=0;i<n;i++){
        if(s>=-eps){
            while(j<n-1 && hi[j]>=eps) j++;
            s+=hi[j];
            res[i]=j++;
        }else{
            while(k<n-1 && hi[k]<eps) k++;
            s+=hi[k];
            res[i]=k++;
        } 
    }
    printf("yes\n");
    for(i=0;i<n;i++){
        printf("%d",1+res[i]);
        if(i==n-1) printf("\n");
        else printf(" ");
    }
}
