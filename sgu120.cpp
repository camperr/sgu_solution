/*
 * =====================================================================================
 *
 *       Filename:  sgu120.cpp
 *
 *    Description:  nan
 *
 *        Version:  1.0
 *        Created:  04/19/2012 08:28:04 PM
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
#include <cmath>
using namespace std;
struct point{
	double x,y;
};
int n,a,b;
point ply[157];
double dis(point beg,point end){
	return sqrt((beg.x-end.x)*(beg.x-end.x)+(beg.y-end.y)*(beg.y-end.y));
}
void solve(){
	int i,j,k;
	double r,to,t1,a0,b0,c0;
	double alp,bel;
	alp=2*pi*(b-a)/n;
	point f,s;
	f=ply[a-1];
	s=ply[b-1];
	r=dis(f,s)/sin(alp/2);
	t0=f.x-s.x;
	t1=f.y-s.y;
	t2=-t0/t1;
	double mx,my;
	mx=(f.x+s.x)/2;
	my=(f.y+s.y)/2;
	t3=(t0*mx+t1*my)/t1;
	a0=1+t2*t2;
	b0=-2*f.x+2*t2*(t3-f.y);
	c0=f.x*f.x+(t3-f.y)*(t3-f.y)-r*r;
	double el=b0*b0-4*a0*c0;
	if(el>=0){
		double x1,y1,x2,y2;
		x1=(-b0-sqrt(el))/(2*a0);
		y1=t2*x1+t3;
		x2=(-b0+sqrt(el))/(2*a0);
		y2=t2*x2+t3;
		//--------
		//
		//
		t0=cos(alp);
		t1=sin(alp);
		for(i=0;i<n;i++){
			ply[a+i-1].x=(f.x-x1)*t0-(f.y-y1)*t1+x1;
			ply[a+i-1].y=(f.y-y1)*t0+(f.x-x1)*t1+y1;
		}
		for(i=0;i<n;i++){
			printf("%f %f\n",ply[i].x,ply[i].y);
		}
	}
}
int main(){
	scanf("%d %d %d",&n,&a,&b);
	scanf("%lf %lf %lf %lf",&ply[a-1].x,&ply[a-1].y,&ply[b-1].x,&ply[b-1].y);
	solve();
}
