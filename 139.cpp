/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int tb[17];
int main(){
    int i,j,k;
    freopen("in.txt","r",stdin);
    for(i=0;i<16;i++){
        scanf("%d",tb+i);
        if(tb[i]==0) k=6-i/4-(i%4);
    }
    for(i=0;i<16;i++){
        for(j=0;j<i;j++){
            if(tb[i]<tb[j])
                k++;
        }
    }
    if(k & 1) printf("YES\n");
    else printf("NO\n");
}
