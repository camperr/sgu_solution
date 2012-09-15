#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[5007];
char prev[5007],res[5007];
int main(){
	freopen("in.txt","r",stdin);
	scanf("%s %s",prev,res);
	int i,j,cnt;
	int si=strlen(prev),sj=strlen(res);
	if(si!=sj){
		printf("-1\n");
		return 0;
	}
	int cnt0=0;
	int cnt1=0;
	memset(f,-1,sizeof(f));
	for(i=0;i<si;i++){
		if(prev[i]=='+') cnt0++;
		if(res[i]=='+') cnt1++;
		if(prev[i]=='+' && res[i]=='-') f[i]=0;
		else if(prev[i]=='-' && res[i]=='+') f[i]=1;
	}
	if(cnt0!=cnt1){
		printf("-1\n");
		return 0;
	}
	cnt=0;
	for(i=0,j=0;i<si;i++,j++){
		while(i<si && f[i]==-1) i++;
		while(j<si && (f[j]==-1 || f[i]^f[j]==0)) j++;
		if(j>=si) break;
		f[j]=-1;
		cnt+=(j-i);
		printf("%d %d\n",i,j);
	}	
	printf("%d\n",cnt);
}
