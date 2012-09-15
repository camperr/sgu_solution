#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
	double a,b,x;
	scanf("%lf %lf %lf",&a,&b,&x);
	double y=1-x/(b-a)/60;
	printf("%.7lf\n",1-y*y);
}
