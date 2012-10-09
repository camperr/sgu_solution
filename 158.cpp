/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN=307;
int n,m,L;
int ps[MAXN],door[MAXN];
double ans,fs;
double min(double a,double b){
    return a<b?a:b;
}
void getDistance(double s){
    int i,j;
    double dis=0;
    for(i=0,j=0;i<n;i++){
        while(j<m-1 && s+door[j]<=ps[i]) j++;
        if(j==0 || (s+door[j]<=ps[i] && j==m-1)) dis+=abs(s+door[j]-ps[i]);
        else dis+=min(ps[i]-s-door[j-1],s+door[j]-ps[i]);
    }
    if(ans<dis){
        fs=s;
        ans=dis;
    }
}
void solve(){
    int i,j;
    ans=0;
    double s;
    for(i=0;i<n;i++){
        for(j=0;j<m-1;j++){
            s=ps[i]-(door[j]+door[j+1])/2.0;
            if(s>=0 && s+door[m-1]<=L) getDistance(s);
        }
    }
    getDistance(0);
    getDistance(L-door[m-1]);
}
int main(){
    int i;
    freopen("in.txt","r",stdin);
    scanf("%d %d",&L,&n);
    for(i=0;i<n;i++){
        scanf("%d",ps+i);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        if(i==0) door[i]=0;
        else scanf("%d",door+i);
    }
    solve();
    printf("%lf %lf\n",fs,ans);
}

