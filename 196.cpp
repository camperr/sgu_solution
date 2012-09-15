/*
 * File:  196.cpp
 * Author:  nzh@uestc
 */
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN=100007;
int n,m;
long long de[MAXN];
int main(){
    int i,j;
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    memset(de,0,sizeof(de));
    for(i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        u--,v--;
        de[u]++;
        de[v]++;
    }
    long long ans=0;
    for(i=0;i<n;i++){
        ans+=de[i]*de[i];
    }
    printf("%I64d\n",ans);
}

