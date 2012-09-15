#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double pi=3.14159265358979323846;
const double eps=1e-9;
struct point{
	double x,y;
};
int n,a,b;
point ply[157];
double cor(double x){
	if(x<0 && x+eps>=0) return 0.0;
	return x;
}
void solve(){
	int i;
	double alp,bel;
	alp=2*pi/n;
	point f,s;
	f=ply[a];
	s=ply[b];
	double x1,y1;
	bel=(pi-alp*(a-b))/2;
	x1=(s.x+f.x-(s.y-f.y)*tan(bel))/2;
	y1=(s.y+f.y+(s.x-f.x)*tan(bel))/2;
	for(i=1;i<=n;i++){
		bel=alp*(a-i);
		ply[i].x=(f.x-x1)*cos(bel)-(f.y-y1)*sin(bel)+x1;
		ply[i].x=cor(ply[i].x);			
		ply[i].y=(f.y-y1)*cos(bel)+(f.x-x1)*sin(bel)+y1;
		ply[i].y=cor(ply[i].y);
		printf("%.6lf %.6lf\n",ply[i].x,ply[i].y);
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d %d %d",&n,&a,&b);
	scanf("%lf %lf %lf %lf",&ply[a].x,&ply[a].y,&ply[b].x,&ply[b].y);
	if(a<b){
		int t=a;
		a=b;
		b=t;
	}
	solve();
}
