#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
struct pnt{
	int x,y;
	int u,v;
} pt[10007];
struct itm{
	int no,v;
	bool operator<(const itm &ot)const{
		return v<ot.v;
	}
};
vector<itm> xc[20007];
vector<itm> yc[20007];
int tL,cnt,n;
void label(int a,int b){
	if(pt[a].u==-1) pt[a].u=b;
	else pt[a].v=b;
}
bool vis[10007];
bool canFindSolution;
bool cross(int u,int v){
	int i,j;
	int beg,end;
	if(pt[u].x==pt[v].x){
		beg=pt[u].y<pt[v].y?pt[u].y:pt[v].y;
		end=pt[u].y^pt[v].y^beg;
		for(i=beg+1;i<end;i++){
			int si=yc[i].size();
			for(j=0;j<si;j+=2){
				if(yc[i][j].v<pt[u].x && pt[u].x<yc[i][j+1].v) return true;
			}
		}
	}else{
		beg=pt[u].x<pt[v].x?pt[u].x:pt[v].x;
		end=pt[u].x^pt[v].x^beg;
		for(i=beg+1;i<end;i++){
			int si=xc[i].size();
			for(j=0;j<si;j+=2){
				if(xc[i][j].v<pt[u].y && pt[u].y<xc[i][j+1].v) return true;
			}
		}
	}
	return false;
}
void dfs(int u){
	int v;
	if(cnt==n-1 && pt[u].u!=0 &&  pt[u].v!=0) {
		canFindSolution=false;
		return;
	}
	if(!vis[pt[u].u]) v=pt[u].u;
	else if(!vis[pt[u].v]) v=pt[u].v;
	else if(cnt==n-1) v=0;
	else return;
	if(cross(u,v)) {
		canFindSolution=false;
		return;
	}
	vis[v]=true;
	cnt++;
	tL+=abs(pt[u].x-pt[v].x)+abs(pt[u].y-pt[v].y);
	dfs(v);
}
int main(){
	int i,j;
	itm add;
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	memset(pt,-1,sizeof(pt));
	for(i=0;i<n;i++){
		scanf("%d %d",&pt[i].x,&pt[i].y);
		pt[i].x+=10000;
		pt[i].y+=10000;
		add.no=i;
		add.v=pt[i].x;
		yc[pt[i].y].push_back(add);
		add.v=pt[i].y;
		yc[pt[i].x].push_back(add);
	}

	canFindSolution=true;
	int sx,sy;
	for(i=0;i<20007;i++){
		sx=xc[i].size();
		sy=yc[i].size();
		sort(xc[i].begin(),xc[i].end());
		sort(yc[i].begin(),yc[i].end());
		if((sx%2!=0) || (sy%2!=0)){
			canFindSolution=false;
			break;
		}
		for(j=0;j<sx;j+=2){
			label(xc[i][j].no,xc[i][j+1].no);
			label(xc[i][j+1].no,xc[i][j].no);
		}
		for(j=0;j<sy;j+=2){
			label(yc[i][j].no,yc[i][j+1].no);
			label(yc[i][j+1].no,yc[i][j].no);
		}
	}
	//for(i=0;i<n;i++) printf("%d %d\n",pt[i].u,pt[i].v);
	if(canFindSolution){
		memset(vis,false,sizeof(vis));
		vis[0]=true;
		tL=0,cnt=0;
		dfs(0);
		if(cnt!=n) canFindSolution=false;
	}
	if(!canFindSolution) printf("0\n");
	else printf("%d\n",tL);
}
