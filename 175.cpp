#include<stdio.h>
int findPos(int n,int p){
	if(n==1) return 1;
	if(p<=n/2) return n-n/2+findPos(n/2,1+n/2-p);
	return findPos(n-n/2,n-n/2+1-(p-n/2));
}
int main(){
	int n,p;
	scanf("%d %d",&n,&p);
	printf("%d\n",findPos(n,p));
}
