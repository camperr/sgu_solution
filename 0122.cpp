#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct ver{
	int a,b;
} vr[1007];
char st[10000];
bool conn[1007][1007];
struct edge{
	int v,next;
} e[100007];
int si,n,ls;
int beg,end;
int head[1007];
bool vis[1007];
bool fd[1007];
int dfs(int c){
	int i;
	vis[c]=true;
	for(i=0;i<n;i++){
		if(conn[c][i] && !vis[i]){
			ls++;
			if(vr[c].a==-1){
				vr[c].a=i;
			}else vr[c].b=i;
			if(vr[i].a==-1) vr[i].a=c;
			else vr[i].b=c;
			return dfs(i);
		}
	}
	return c;
}
void find_cir(){
	int i,j,k;
	memset(fd,false,sizeof(fd));
	i=vr[beg].a,j=beg;
	fd[beg]=true;
	while(true){
		if(conn[beg][i] && conn[j][end]){
			vr[beg].b=i;
			if(vr[i].a==j) vr[i].a=beg;
			else vr[i].b=beg;
			if(vr[end].b==-1)vr[end].b=j;
			else vr[end].a=j;
			if(vr[j].a==i) vr[j].a=end;
			else vr[j].b=end;
			break;
		}	
		fd[i]=true;
		if(i==end) break;
		if(vr[i].a!=j) {
			j=i;
			i=vr[i].a;
		}else {
			j=i;
			i=vr[i].b;
		}
	}

}
void cut_cir(){
	int i,j,k;
	memset(fd,false,sizeof(fd));
	i=beg;
	while(true){
		fd[i]=true;
		j=head[i];
		while(j!=-1){
			k=e[j].v;
			if(vis[k]==false){
				ls++;
				beg=k;
				vr[k].a=i;
				end=vr[i].b;
				vr[i].b=k;
				if(vr[end].a==i) vr[end].a=-1;
				else vr[end].b=-1;
				return;
			}else{
				head[i]=e[j].next;
			}
			j=e[j].next;
		}
		if(!fd[vr[i].a]) i=vr[i].a;
		else if(!fd[vr[i].b]) i=vr[i].b;
		else break;
	}
}
int main(){
	freopen("in.txt","r",stdin);
	int i,j,no,v;
	scanf("%d",&n);
	memset(conn,false,sizeof(conn));
	memset(head,-1,sizeof(head));
	si=0;
	getchar();
	for(i=0;i<n;i++){
		gets(st);
		no=0;
		int ss=strlen(st);
		for(j=0;j<ss;j++){
			if(st[j]>='0' && st[j]<='9'){
				no=no*10+st[j]-'0';
			}else{
				conn[i][no-1]=true;
				e[si].v=no-1;
				e[si].next=head[i];
				head[i]=si++;
				no=0;
			}
		}	
		if(no) conn[i][no-1]=true;
	}
	memset(vr,-1,sizeof(vr));
	memset(vis,false,sizeof(vis));
	ls=1;
	beg=dfs(0);
	end=dfs(0);
	while(ls<n){
		//printf("%d %d %d\n",beg,end,ls);
		find_cir();
		cut_cir();
		beg=dfs(beg);
	}
	find_cir();
	memset(vis,false,sizeof(vis));
	int c=0;
	for(i=0;i<n;i++){
		vis[c]=true;
		printf("%d ",c+1);
		c=vis[vr[c].a]?vr[c].b:vr[c].a;
	}
	printf("1\n");
	return 0;
}

