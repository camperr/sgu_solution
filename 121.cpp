/*
 * =====================================================================================
 *
 *       Filename:  121.cpp
 *
 *    Description:  none
 *
 *        Version:  1.0
 *        Created:  04/22/2012 10:35:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct ver{
	int anc,n,deg;
	bool all2;
}v[107];
bool vis[107][107];
bool vis_v[107];
int n;
int cr[107][107];
void init(){
	memset(vis,false,sizeof(vis));
	memset(cr,0,sizeof(cr));
	memset(vis_v,false,sizeof(vis_v));
	int i,j;
	for(i=0;i<n;i++){
		v[i].anc=i;
		v[i].n=1;
		v[i].deg=0;
		v[i].all2=false;
	}
}
int find(int a){
	if(v[a].anc==a) return a;
	else{
		int b=find(v[a].anc);
		v[a].anc=b;
		return b;
	}
}

void _union(int a,int b){
	int aa=find(a),ab=find(b);
	if(aa!=ab){
		v[aa].anc=ab;
		v[ab].n+=v[aa].n;
		if(v[aa].all2==false) v[ab].all2=false;
	}
}
void dfs(int a,int c){
	int i;
	vis_v[a]=true;
	for(i=0;i<n;i++){
		if(vis[a][i]){
			cr[a][i]=cr[i][a]=c;
			vis[a][i]=vis[i][a]=false;
			c=3-c;
			dfs(i,c);
		}
	}	
}
int main(){
	int i,j,k;
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	init();
	for(i=0;i<n;i++){
		int a;
		while(scanf("%d",&a) && a!=0){
			vis[i][a-1]=true;
			v[i].deg++;
		}
		if(v[i].deg==2) v[i].all2=true;
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(vis[i][j]){
				_union(i,j);
			}	
		}
	}
	for(i=0;i<n;i++){
		printf("%d anc:%d n:%d deg:%d all2:%d\n",i,v[i].anc,v[i].n,v[i].deg,v[i].all2);
	}
	bool yes=true;
	for(i=0;i<n;i++){
		if(!vis_v[i]){
			if(v[i].deg!=2) dfs(i,1);
			else{
				int a=find(i);
				if(v[a].all2){
					if(v[a].n%2==1){
						yes=false;
						break;
					}
					else{
						dfs(i,1);
					}
				}
			}
		}
	}
	if(yes) {
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(cr[i][j]>0){
					printf("%d ",cr[i][j]);
				}
			}
			printf("0\n");
		}
	}
	else printf("No solution\n");
}
