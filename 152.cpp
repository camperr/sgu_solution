#include <stdlib.h>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int per[10007],res[10007];
int main(){
	int i;
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	int sum=0;
	for(i=0;i<n;i++){
		scanf("%d",per+i);
		sum+=per[i];
	}
	int sumDown=0;
	for(i=0;i<n;i++){
		res[i]=per[i]*100/sum;
		sumDown+=res[i];
	}
	//printf("%d %d\n",sumDown,100);
	int dif=100-sumDown;
	for(i=0;i<n;i++){
		if(res[i]*sum!=per[i]*100 && dif){
			res[i]++;
			dif--;
		}
		printf("%d",res[i]);
		if(i==n-1) printf("\n");
		else printf(" ");
	}
}
