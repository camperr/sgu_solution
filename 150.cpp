/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <cmath>
using namespace std;
int bx,by,ex,ey,n;
class Point{
    public:
        int x,y;
        int pointProduct(Point sec){
            return x*sec.x+y*sec.y;
        }
        int crossProduct(Point sec){
            return x*sec.y-y*sec.x;
        }
};
bool noSolution=false;
int d[8][3]={{-1,-1,2},{1,-1,3},{1,1,0},{-1,1,1},{0,-1,6},{1,0,7},{0,1,4},{-1,0,5}};
class Cell{
    public:
        int ic,oc;
        Point lb;
        Point ver[4];
        void setLb(int x,int y){
            lb.x=x;
            lb.y=y;
        }
        void initVer(){
            ver[0]=lb;
            ver[1].x=lb.x+1;
            ver[1].y=lb.y;
            ver[2].x=lb.x+1;
            ver[2].y=lb.y+1;
            ver[3].x=lb.x;
            ver[3].y=lb.y+1;
        }
        void crossPoint(Point ed){
           int i;
           for(i=0;i<4;i++){
                if(ed.pointProduct(ver[i])>=0 && ed.crossProduct(ver[i])==0){
                    if(ver[i].x==ed.x && ver[i].y==ed.y) noSolution=true;
                    if(ic==-1){
                        ic=i;
                    }else if(ic!=i){
                        oc=i;
                    } 
                } 
           }
        }
        void crossEdge(Point ed){
            int i;
            for(i=0;i<4;i++){
                if(ed.crossProduct(ver[i])*ed.crossProduct(ver[(i+1)%4])<0){
                    if(ic==-1){
                        ic=4+i;
                    }else if(ic!=4+i){
                        oc=i+4;
                    }
                }
            }
        }
        void getNext(){
            lb.x+=d[oc][0];
            lb.y+=d[oc][1];
            ic=d[oc][2];
            oc=-1;
        }
};
Point ed;
Cell ce;
void initalize(){
    ed.x=ex-bx;
    ed.y=ey-by;
    if(ed.x==0 || ed.y==0) {
        noSolution=true;
        return;
    }
    ce.setLb(ed.x<0?-1:0,ed.y<0?-1:0);
    if(ed.x<0 && ed.y<0) ce.ic=2;
    else if(ed.x>0 && ed.y>0) ce.ic=0;
    else if(ed.x<0 && ed.y>0) ce.ic=1;
    else ce.ic=3;
}
void solve(){
    int i;
    for(i=0;i<n-1;i++){
        ce.initVer();
        ce.crossPoint(ed);
        ce.crossEdge(ed);
        printf("%d %d %d %d\n",ce.lb.x,ce.lb.y,ce.ic,ce.oc);
        ce.getNext();
    }
}
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d %d %d %d %d",&bx,&by,&ex,&ey,&n);
    initalize();
    solve();
    if(noSolution) printf("no solution\n");
    else printf("%d %d\n",ce.lb.x+bx,ce.lb.y+by);
}
