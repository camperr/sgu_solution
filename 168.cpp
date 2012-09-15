#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=1007;
int grid[MAXN][MAXN];
int ans[MAXN][MAXN];
int n,m;
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",grid[i]+j);
		}
	}
	int s;
	for(s=n+m-2;s>=0;s--){
		for(j=min(m-1,s);j>=0 && s-j<n;j--){
			i=s-j;
			ans[i][j]=grid[i][j];
			if(i<n-1) ans[i][j]=min(ans[i][j],ans[i+1][j]);
			if(j<m-1) ans[i][j]=min(ans[i][j],ans[i][j+1]);
			if(i && j<m-1) ans[i][j]=min(ans[i][j],ans[i-1][j+1]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d",ans[i][j]);
			if(j!=m-1) printf(" ");
			else printf("\n");
		}
	}
}
