/*
** Author: nzh@UESTC
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
const int MAXN=10007;
const int eps=1e-5;
int n;
bool iszero(double a){
	if(a>eps || a<-eps) return false;
	return true;
}
struct pnt{
	double x,y;
};
pnt md[MAXN];
pnt ver[MAXN];
int main(){
	double x,y;
	int i;
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf %lf",&md[i].x,&md[i].y);
	}
	x=2*md[n-1].x,y=2*md[n-1].y;
	for(i=0;i<n-1;i++){
		if(i%2){				//奇数加上原值，偶数项加上相反数，第0项应该是取相反数
			x+=2*md[i].x;
			y+=2*md[i].y;
		}else{
			x+=-2*md[i].x;
			y+=-2*md[i].y;
		}
	}
	//printf("%lf %lf\n",x,y);
	if(n%2 || (iszero(x) && iszero(y))){
		printf("YES\n");
		ver[n-1].x=x/2;
		ver[n-1].y=y/2;
		for(i=n-2;i>=0;i--){
			ver[i].x=2*md[i].x-ver[i+1].x;
			ver[i].y=2*md[i].y-ver[i+1].y;
		}
		for(i=0;i<n;i++){
			printf("%lf %lf\n",ver[i].x,ver[i].y);
		}
	}else printf("NO\n");
}

