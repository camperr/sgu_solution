#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=16007;
int head[MAXN];
struct edge{
	int v,next;
} e[2*MAXN];
int totalEdge;
bool vis[MAXN];
int cnt[MAXN],ans[MAXN];

int n;
void initialize(){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	int u,v,i;
	memset(head,-1,sizeof(head));
	totalEdge=0;
	for(i=0;i<n-1;i++){
		scanf("%d %d",&u,&v);
		u--,v--;
		e[totalEdge].v=u;
		e[totalEdge].next=head[v];
		head[v]=totalEdge++;
		e[totalEdge].v=v;
		e[totalEdge].next=head[u];
		head[u]=totalEdge++;
	}
	memset(cnt,-1,sizeof(cnt));
	memset(vis,false,sizeof(vis));
	vis[0]=true;
}
int dfs(int u){
	int i,j,v,sumOfCnt;
	for(v=head[u],sumOfCnt=1;v!=-1;v=e[v].next){
		if(!vis[e[v].v]){
			vis[e[v].v]=true;
			j=dfs(e[v].v);
			sumOfCnt+=j;
			cnt[u]=cnt[u]>j?cnt[u]:j;	
		}
	}
	j=n-sumOfCnt;
	if(j) cnt[u]=cnt[u]>j?cnt[u]:j;	
	return sumOfCnt;
	
}
void solve(){
	dfs(0);
	int i,j,minCnt;
	minCnt=MAXN;
	for(i=0;i<n;i++) minCnt=minCnt<cnt[i]?minCnt:cnt[i];
	for(i=0,j=0;i<n;i++){
		if(minCnt==cnt[i]){
			ans[j++]=i;
		}
	}
	printf("%d %d\n",minCnt,j);
	for(i=0;i<j;i++){
		printf("%d",ans[i]+1);
		if(i!=j-1) printf(" ");
		else printf("\n");
	}
}
int main(){
	initialize();
	solve();
}
