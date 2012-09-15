#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const double eps=1e-8;
struct point{
    double x,y,z;
};
struct line{
    point beg,dir;
};
struct sphere{
    point c;
    double r;
};
struct its{
    point it;
    int no;
} it[107];
sphere sp[57];
int sit;
int result[17];
line init;
int n;
void readdata(){
    freopen("in.txt","r",stdin);
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%lf %lf %lf %lf",&sp[i].c.x,&sp[i].c.y,&sp[i].c.z,&sp[i].r);
    scanf("%lf %lf %lf %lf %lf %lf",&init.beg.x,&init.beg.y,&init.beg.z,&init.dir.x,&init.dir.y,&init.dir.z);
    init.dir.x-=init.beg.x;
    init.dir.y-=init.beg.y;
    init.dir.z-=init.beg.z;
}
bool is_positive(double a){
    if(a>eps) return true;
    return false;
}
void find_intersection(int k){
    //找到与第k个球的交点
    double a,b,c,a0,b0,c0,t0,t1,t2;
    a=init.beg.x-sp[k].c.x;
    b=init.beg.y-sp[k].c.y;
    c=init.beg.z-sp[k].c.z;
    a0=init.dir.x*init.dir.x+init.dir.y*init.dir.y+init.dir.z*init.dir.z;
    b0=2*init.dir.x*a+2*init.dir.y*b+2*init.dir.z*c;
    c0=a*a+b*b+c*c-sp[k].r*sp[k].r;
    if(b0*b0>=4*a0*c0){
        t0=sqrt(b0*b0-4*a0*c0);
        t1=(-b0+t0)/(2*a0);
        t2=(-b0-t0)/(2*a0);
        it[sit].it.x=init.dir.x*t1+init.beg.x;
        it[sit].it.y=init.dir.y*t1+init.beg.y;
        it[sit].it.z=init.dir.z*t1+init.beg.z;
        it[sit].no=k;
        sit++;
        it[sit].it.x=init.dir.x*t2+init.beg.x;
        it[sit].it.y=init.dir.y*t2+init.beg.y;
        it[sit].it.z=init.dir.z*t2+init.beg.z;
        it[sit].no=k;
        sit++;
    }
}
double dis(point a,point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
void find_next_dir(point a,point b){

    double t=-2*(a.x*b.x+a.y*b.y+a.z*b.z)/(b.x*b.x+b.y*b.y+b.z*b.z);
    init.dir.x=b.x*t+a.x;
    init.dir.y=b.y*t+a.y;
    init.dir.z=b.z*t+a.z;
}
int find_next(){
    //找到下一个起点和方向向量
    int i,k=-1,k1=-1;
    double d,cd;
    for(i=0;i<sit;i++){
       //printf("it %d: %d\n",i,it[i].no);
       double dd=(it[i].it.x-init.beg.x)*init.dir.x+(it[i].it.y-init.beg.y)*init.dir.y+(it[i].it.z-init.beg.z)*init.dir.z;
       if(is_positive(dd)){
            cd=dis(init.beg,it[i].it);
           // printf("cd %d: %f\n",i,cd);
            if(k==-1 || is_positive(d-cd)){
                d=cd;
                k=it[i].no;
                k1=i;
            }
       }
    }
    if(k==-1) return -1;
    point law;
    law.x=it[k1].it.x-sp[k].c.x;
    law.y=it[k1].it.y-sp[k].c.y;
    law.z=it[k1].it.z-sp[k].c.z;
    find_next_dir(init.dir,law);
    init.beg=it[k1].it;
    return k;
}
void solve(){
    int i,j,k=-1;
    for(i=0;i<13;i++){
        sit=0;
        for(j=0;j<n;j++) {
            if(i==0 || j!=result[i-1])
                find_intersection(j);
        }
        result[i]=find_next();
        if(result[i]==-1) break;
        k=i;
    }
    for(i=0;i<=k;i++){
        if(i) printf(" ");
        if(i>=10){
            printf("etc.\n");
            break;
        }
        printf("%d",result[i]+1);
    }
}
int main(){
    readdata();
    solve();
}
