#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int bigMod(int k){
	int d=0,i;
	for(i=0;i<k-1;i++){
		d=(d*10+1)%7;
	}
	return d;
}
int main(){
	int k;
	freopen("in.txt","r",stdin);
	scanf("%d",&k);
	int ans=0;
	if(k==1) ans=8;
	else{
		ans=1;
		if((k-1)%3==0) {
			ans+=2;
			if(bigMod(k)==0) ans+=1;
		}
	}
	printf("%d\n",ans);
}
