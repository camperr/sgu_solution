#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=207;
int ans[MAXN];
bool notcon[MAXN][MAXN],vis[MAXN],noAns;
int n,m;
void dfs(int no,int d){
	int i;
	for(i=0;i<n;i++){
		if(notcon[no][i]){
			notcon[no][i]=notcon[i][no]=false;
			vis[i]=true;
			if(d==ans[i]){
				noAns=true;
				return;
			}
			ans[i]=3-d;
			dfs(i,3-d);
		}
		if(noAns) return;
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d %d",&n,&m);
	int i;
	memset(notcon,false,sizeof(notcon));
	for(i=0;i<m;i++){
		int t,s;
		scanf("%d %d",&t,&s);
		s--,t--;
		notcon[t][s]=notcon[s][t]=true;
	}
	memset(ans,-1,sizeof(ans));
	memset(vis,false,sizeof(vis));
	noAns=false;
	for(i=0;i<n;i++){
		if(!vis[i]) {
			ans[i]=1;
			dfs(i,1);
		}
		if(noAns) break;
	}
	if(noAns) printf("no\n");
	else {
		printf("yes\n");
		int cntOne=0;
		for(i=0;i<n;i++)
			if(ans[i]==1) cntOne++;
		printf("%d\n",cntOne);
		for(i=0;i<n;i++){
			if(ans[i]==1){
				cntOne--;
				printf("%d",i+1);
				if(cntOne) printf(" ");
				else printf("\n");
			}
		}
	}
}
