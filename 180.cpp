#include <cstdio>
#include <cstring>
using namespace std;
int nmb[70007],n;
int nmb_s[70007];
long long cntOfInv;
void merge(int u,int v){
	int i,j,k;
	int mid=(u+v)/2;
	if(u<v){
		merge(u,mid);
		merge(mid+1,v);
	}
	for(i=u,j=mid+1,k=u;k<=v;k++){
		if(j>v || (i<=mid && nmb[i]<=nmb[j])){
			nmb_s[k]=nmb[i];
			cntOfInv+=j-mid-1;
			i++;
		}else{
			nmb_s[k]=nmb[j];
			j++;
		}
	}
	for(i=u;i<=v;i++) nmb[i]=nmb_s[i];
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++){
		scanf("%d",nmb+i);
	}
	cntOfInv=0;
	merge(0,n-1);
	printf("%I64d\n",cntOfInv);
}
