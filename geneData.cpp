/*
 * Author: nzh@UESTC
 */
#include <stdlib.h>
#include <ctime>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n,m,i,j;
	n=1000;
	m=1000;
	freopen("in.txt","w",stdout);
	printf("%d %d\n",n,m);
	srand(time(0));
	for(i=0;i<n;i++){
		int k=rand()%100+1;
		k=k<m?k:m;
		for(j=0;j<k;j++){
			printf("%d ",rand()%m+1);
		}
		printf("\n");
	}
}
