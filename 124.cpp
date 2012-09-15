/*
 * =====================================================================================
 *

 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/18/2012 08:45:24 AM
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
#include <algorithm>
using namespace std;
const int MAXN=10007;
struct line{
	int x0,y0,x1,y1;
}ln[MAXN];
int n;
double x,y;
bool inLine(int a){
	if(ln[a].x0==x && ln[a].x1==x){
		if((ln[a].y0<=y && y<=ln[a].y1) || (ln[a].y1<=y && y<=ln[a].y0)) return true;
	}else if(ln[a].y0==y && ln[a].y1==y){
		if((ln[a].x0<=x && x<=ln[a].x1) || (ln[a].x1<=x && x<=ln[a].x0)) return true;
	}
	return false;
}
bool cross(int a,double xx,double yy){
	if(ln[a].x0==ln[a].x1 && xx<ln[a].x0){
		if((ln[a].y0<yy && yy<ln[a].y1) || (ln[a].y1<yy && yy<ln[a].y0)) return true;
	}
	return false;
}
int main(){
	int i,j,k,res,f;
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d %d %d %d",&ln[i].x0,&ln[i].y0,&ln[i].x1,&ln[i].y1);
		//printf("%d %d %d %d\n",ln[i].x0,ln[i].y0,ln[i].x1,ln[i].y1);
	}
	scanf("%lf %lf",&x,&y);
	res=-1;
	k=0,j=0;
	for(i=0;i<n;i++){
		if(inLine(i)) {
			res=2;
			break;
		}	
		if(cross(i,x+0.5,y+0.5)) k++;
	}
	if(res==2) printf("BORDER\n");
	else{
		res=k%2;
		if(res)
			printf("INSIDE\n");
		else printf("OUTSIDE\n");
	}
}
