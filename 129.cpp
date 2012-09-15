/*
** Author: nzh@UESTC
*/
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN=1007;
const double eps=1e-5;
const double MAXX=1e6;
struct vec{
	double x,y;
};
vec beg[MAXN],end[MAXN],ch[MAXN];
int n,m;
int hl[MAXN],hlSi;
vec cp[5];
int cpSi;
int judge(double a){
	if(a>=eps) return 1;
	else if(a<=-eps) return -1;
	else return 0;
}
double crossProduct(vec a,vec b,vec c){
	vec u,v;
	u.x=b.x-a.x;
	u.y=b.y-a.y;
	v.x=c.x-a.x;
	v.y=c.y-a.y;
	return u.x*v.y-u.y*v.x;
}
void giftWrapping(){
	int i,j,k;
	hl[0]=0;
	j=0;
	while(true){
		for(k=-1,i=0;i<n;i++){
			if(i!=hl[j]){
				if(k==-1 || judge(crossProduct(ch[hl[j]],ch[i],ch[k]))==1){
					k=i;
				}
			}
		}
		hl[++j]=k;
		if(k==hl[0]) break;
	}
	hlSi=j;
}
bool onSegment(vec a,vec b,vec c){
	return judge(crossProduct(a,b,c))==0 && judge(a.x-c.x)*judge(b.x-c.x)<=0 && judge(a.y-c.y)*judge(b.y-c.y)<=0;
}
int cross(vec a,vec b,vec c,vec d){
	double d1=crossProduct(a,b,c);
	double d2=crossProduct(a,b,d);
	if(judge(d1)==0 && judge(d2)==0) return 0;
	double d3=crossProduct(c,d,a);
	double d4=crossProduct(c,d,b);
	if(judge(d1)*judge(d2)==-1 && judge(d3)*judge(d4)==-1){
		double x=d3>0?d3:(-d3);
		double y=d4>0?d4:(-d4);
		cp[cpSi].x=(x*b.x+y*a.x)/(x+y);
		cp[cpSi].y=(x*b.y+y*a.y)/(x+y);
		cpSi++;
		return 1;
	}else if(onSegment(a,b,d)) return -1;
	else if(onSegment(c,d,a)){
		cp[cpSi++]=a;
		return 1;
	}else if(onSegment(c,d,b)){
		cp[cpSi++]=b;
		return 1;
	}else if(onSegment(a,b,c)){
		cp[cpSi++]=c;
		return 1;
	}else return -1;
}
int checkInHull(vec a){
	int i;
	int cnt=0;
	vec b,c=a;
	c.y-=0.01;
	b.x=MAXX;
	b.y=c.y;
	for(i=0;i<hlSi;i++){
		if(onSegment(ch[hl[i]],ch[hl[i+1]],a)) return 0;
		cpSi=0;
		int f=cross(a,b,ch[hl[i]],ch[hl[i+1]]);
		if(f==1){
			cnt++;
		}
	}
	return cnt%2==1?1:-1;
}
double dist(vec a,vec b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void solve(){
	int i,j;
	double dis=0;
	for(i=0;i<m;i++){
		int begInHl=checkInHull(beg[i]);
		int endInHl=checkInHull(end[i]);
		bool par=false;
		cpSi=0;
		for(j=0;j<hlSi;j++){
			int f=cross(beg[i],end[i],ch[hl[j]],ch[hl[j+1]]);
			if(f==0){
				par=true;
				break;
			}
		}
		if(par) dis=0;
		else if(cpSi==2) dis=dist(cp[0],cp[1]);
		else if(cpSi==1){
			if(begInHl==-1 && endInHl==-1) dis=0;
			else if(begInHl==1 && endInHl<=0) dis=dist(cp[0],beg[i]);
			else if(begInHl<=0 && endInHl==1) dis=dist(cp[0],end[i]);
			else dis=0;
		}else if(cpSi==0){
			if(begInHl==-1 && endInHl==-1) dis=0;
			else dis=dist(beg[i],end[i]);
		}
		printf("%.2lf\n",dis);
	}
}
int main(){
	int i;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int a,b,c,d;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		ch[i].x=a;
		ch[i].y=b;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		beg[i].x=a;
		beg[i].y=b;
		end[i].x=c;
		end[i].y=d;
	}
	giftWrapping();
	solve();
	return 0;
}