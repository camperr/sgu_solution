/*
 * =====================================================================================
 *
 *       Filename:  131.cpp
 *
 *    Description:  none
 *
 *        Version:  1.0
 *        Created:  06/18/2012 10:08:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long trans[1057][1057];
long long dp[13][1<<12];
int n,m;
void count(){
	int i,j,k;
	memset(trans,0,sizeof(trans));
	trans[(1<<m)-1][0]=1;
	for(i=(1<<m)-2;i>=0;i--){
		for(j=0;j<(1<<m);j++){
			k=0;
			while(k<m && (i & (1<<k))) k++;
			if(j & (1<<k)) trans[i][j]+=trans[i+(1<<k)][j-(1<<k)];
			if(k<m && !(i & (1<<(k+1)))) trans[i][j]+=trans[i+(1<<k)+(1<<(k+1))][j];
			if(k<m && (j & (1<<k)) && (j & (1<<(k+1)))) trans[i][j]+=trans[i+(1<<k)][j-(1<<k)-(1<<(k+1))];
			if(k && (j & (1<<k)) && (j & (1<<(k-1)))) trans[i][j]+=trans[i+(1<<k)][j-(1<<k)-(1<<(k-1))];
			if(k<m && !(i & (1<<(k+1))) && (j & (1<<k))) trans[i][j]+=trans[i+(1<<k)+(1<<(k+1))][j-(1<<k)];
			if(k<m && !(i & (1<<(k+1))) && (j & (1<<(k+1)))) trans[i][j]+=trans[i+(1<<k)+(1<<(k+1))][j-(1<<(k+1))];
		}
	}
}

int main(){
	int i,j,k;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d %d",&n,&m);
	printf("{");
	for(n=0;n<10;n++){
		printf("{");
		for(m=0;m<10;m++){
			if(n<=1 && m<=1){
				printf("0,");
				continue;
			}
			count();
			memset(dp,0,sizeof(dp));
			dp[0][(1<<m)-1]=1;
			for(i=1;i<=n+1;i++){
				for(j=0;j<(1<<m);j++){
					for(k=0;k<(1<<m);k++){
						dp[i][j]+=dp[i-1][k]*trans[k][j];
					}
				}
			}
			printf("%lld",dp[n+1][0]);
			if(m!=9) printf(",");
		}
		printf("},\n");
	}
	printf("}");
}
/*打表提交
#include <stdlib.h>
#include <cstdio>
using namespace std;
long long a[10][10]={
{0,0,1,1,1,1,1,1,1,1},
{0,0,1,0,1,0,1,0,1,0},
{1,1,2,5,11,24,53,117,258,569},
{1,0,5,8,55,140,633,1984,7827,26676},
{1,1,11,55,380,2319,15171,96139,619773,3962734},
{1,0,24,140,2319,21272,262191,2746048,31411948,342302244},
{1,1,53,633,15171,262191,5350806,100578811,1973546988,37873593799},
{1,0,117,1984,96139,2746048,100578811,3238675344,111496884663,3704964324320},
{1,1,258,7827,619773,31411948,1973546988,111496884663,6652506271144,385840008972355},
{1,0,569,26676,3962734,342302244,37873593799,3704964324320,385840008972355,38896105985522272}
};
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	printf("%lld\n",a[n][m]);
}
*/
