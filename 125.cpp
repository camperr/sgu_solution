/*
 * =====================================================================================
 *
 *       Filename:  125.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/18/2012 10:35:02 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int ph[10007];
int n,k;
int main(){
	int i,j,cnt;
	scanf("%d",&k);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",ph+i);
	}
	sort(ph,ph+n);
	int res=0;
	cnt=0;
	for(i=0;i<=n;i++){
		if(i==n || (i && ph[i-1]/1000!=ph[i]/1000)){
			res+=(cnt/k+(int)(cnt%k!=0));
			cnt=1;
		}else cnt++;	
	}
	res+=2;
	printf("%d\n",res);
}
