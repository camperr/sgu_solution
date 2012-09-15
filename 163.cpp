#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,ex;
int pt[107];
int power(int a,int b){
	int r=1;
	while(b){
		r*=a;
		b--;
	}
	return r;
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d %d",&n,&ex);
	int i,j,ans;
	for(i=0;i<n;i++) scanf("%d",pt+i);
	if(ex%2==0){
		ans=0;
		for(i=0;i<n;i++) ans+=power(pt[i],ex);
	}else{
		ans=0;
		for(i=0;i<n;i++){
			if(pt[i]>0) ans+=power(pt[i],ex);
		}
	}
	printf("%d\n",ans);
}
