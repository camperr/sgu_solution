/*
 * Author:  nzh@UESTC
 */
//refer to http://d.ream.at/sgu-162/
#include <stdlib.h>
#include <cmath>
#include <cstdio>
using namespace std;
double volume(double a,double b,double c,double aa,double bb,double cc){
    double m=b*b+c*c-aa*aa;
    double n=a*a+c*c-bb*bb;
    double p=a*a+b*b-cc*cc;
    double eq0=a*a*b*b*c*c;
    double eq1=(a*a*m*m+b*b*n*n+c*c*p*p)/4;
    double eq2=m*n*p/4;
    printf("%lf %lf %lf\n",eq0,eq1,eq2);
    return sqrt(eq0-eq1+eq2)/6;
}
int main(){
    double a,b,c,aa,bb,cc;
    //AB=a,AC=B,AD=c,CD=aa,DB=bb,BC=cc
    freopen("in.txt","r",stdin);
    scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&cc,&bb,&aa);
    printf("%.4lf\n",volume(a,b,c,aa,bb,cc));
}
